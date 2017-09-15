<?php 
/*
	VISTA: entrada de datos por pantalla
*/

require_once('guardar_datos_db.php');

echo "Bienvenido a Vista Prueba UNO <br>";

$idCliente	= $_POST ['idCliente'];
$idSensor	= $_POST ['idSensor'];
$temperatura= $_POST ['temperatura'];

echo "--------------------------<br>";
echo "idCliente: ", $idCliente, "<br>";
echo "idSensor: ", $idSensor, "<br>";
echo "temperatura: ", $temperatura, "<br>";
echo "--------------------------<br>";

if (isset($idCliente) && isset($idSensor) && isset($temperatura))
{
	guardarTemperatura($idCliente,$idSensor,$temperatura);
} else 
	{ 
	echo "<br> Debe ingresar [idCliente][idSensor][temperatura] <br>";
	}

?>