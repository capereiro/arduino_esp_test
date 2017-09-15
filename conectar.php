<?php 

/*
	Funcion del sistema
*/

echo "Conectando DB local <br>";

/*
$conexion2mySql = mysqli_connect("31.220.54.47","cacticom_charly","Panamera911!");
mysql_select_db("cacticom_cultivator",$conexion2mySql);
*/

function conectar (){

$conexion2mySql = mysqli_connect("localhost","charly","lecter69");

	if (!$conexion2mySql)
	{
	  //  printf("Can't connect to localhost. Error: %s\n", mysqli_connect_error());
	    echo("No se pudo conectar al servidor de database ");
	    exit();
	}

	if (!mysqli_set_charset($conexion2mySql, 'utf8'))
	{
	    echo("No se pudo configurar encoding");
	    exit();
	}

	if (!mysqli_select_db($conexion2mySql, 'pruebaiot'))
	{
	    echo("No se pudo conectar a la database");
	    exit();
	}

	echo("Conexion a DB cacti OK <br>");
	return ($conexion2mySql);

}

?>