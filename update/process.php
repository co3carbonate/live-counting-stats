<?php

if(empty($_SERVER['HTTP_X_REQUESTED_WITH']) || strtolower($_SERVER['HTTP_X_REQUESTED_WITH']) != 'xmlhttprequest'
|| !isset($_POST['password']) 
|| !isset($_POST['content'])
|| !isset($_POST['chatFile'])) {
	echo 'Unknown error. Please try again.';
	exit;
}

$password = $_POST['password'];
$content = $_POST['content'];
$chatFile = $_POST['chatFile'];
if($password != 'kaleidoscope') {
	echo 'Error: wrong password. Please try again.';
	exit;
}

$dataFile = '../data/chat' .$chatFile. '.json';
if(!file_exists($dataFile)) {
	$newFile = fopen($dataFile, 'x');
	fwrite($newFile, '[]');
	fclose($newFile);
}

function injectData($file, $data, $position) {
	$fpFile = fopen($file, "rw+");
	$fpTemp = fopen('php://temp', "rw+");
	stream_copy_to_stream($fpFile, $fpTemp, -1, $position);
	fseek($fpFile, $position);
	fwrite($fpFile, $data);
	rewind($fpTemp);
	stream_copy_to_stream($fpTemp, $fpFile);

	fclose($fpFile);
	fclose($fpTemp);
}

injectData($dataFile, $content, 1);

echo 'Database successfully updated';

?>