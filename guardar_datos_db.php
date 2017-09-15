<?php 
/*
	CONTROLADOR: para manejo de persistencia
*/

require_once('conectar.php');

echo "Entrada de datos en mySQL con Stored Procedure<br>";

function guardarTemperatura($idCliente, $idSensor, $temperatura)
	{
	$conexion2mySql = conectar();

	if($conexion2mySql->query("CALL usp_guardarTemperatura('$idCliente', '$idSensor', '$temperatura')"))
	{
    	echo "Procedure: usp_guardarTemperatura > OK";
	}
		else
		{
			echo "Falló CALL: (" . $conexion2mySql->errno . ") " . $conexion2mySql->error;
		}

	$conexion2mySql->close();
	}

/*
	print "<pre>"; 
             if (!$rs->EOF) 
                { 
                echo " indice : ".$rs->fields("indice")." nombre : "$rs->fields("nombre")." apellidos : ".$rs->fields("apellidos")."<br />"; 
                }  
             print "</pre>"; 
*/

?>