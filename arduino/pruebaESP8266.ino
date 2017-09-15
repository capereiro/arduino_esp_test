#include <SoftwareSerial.h>
SoftwareSerial WIFI(3,2); // RX | TX

byte valorPorSerial = 0;

void setup() {  
    
 Serial.begin(19200);
 WIFI.begin(19200);
 Serial.println("Servicio OK");

String ordenesAT[]=
  {  "AT+CWMODE=3",
     "AT+CWQAP",
     "AT+CWJAP=\"Mortorhead\",\"panamera911\"",
   //  "AT+CIFSR" ,
     "AT+CIPMUX=1",
     "AT+CIPSERVER=1,80",
     "END"                 // Para reconocer el fin de los comandos AT
  };


  int index = 0;
     while(ordenesAT[index] != "END")
        {  WIFI.println(ordenesAT[index++]);
           while ( true)
              {   String s = GetLineWIFI();
                  if ( s!= "") Serial.println(s);
                  if ( s.startsWith("no change"))  
                          break;
                  if ( s.startsWith("OK"))  
                          break;
                  if ( s.startsWith("ready"))  
                         break;
                  // if (millis()-T >10000) break; 
              }
          Serial.println("....................");
          
      }

    WIFI.println("AT+CIFSR");
  }

void loop()
  { 

    delay(2000);

 /*    if (WIFI.available())
         { char c = WIFI.read() ;
           Serial.print(c);
         }
     if (Serial.available())
         {  char c = Serial.read();
            WIFI.print(c);
         }
*/

 // String url = "http://127.0.0.1/vista_prueba_1.php?idCliente=ESP8266-1&idSensor=T99&temperatura=66";
  
  
  String url = "http://192.168.0.11/vista_prueba_1.php";
  String data = "idCliente=ESP8266-2&idSensor=T99&temperatura=66";
  String host = "192.168.0.11";  //url o IP del servidor

 // http://localhost/vista_prueba_1.php?idCliente=almiron&idSensor=T02&temperatura=23

//Solo para prototipado
//Al enviar un valor entre 1 y 5 se envía a persistir valores de temperatura en la nube

if (Serial.available() > 0) {
  // read the incoming byte:
  valorPorSerial = Serial.read();
  valorPorSerial-= 48; //Se le resta 48 al nro ASCII leído para transformarlo a int de forma precaria
  
    if (valorPorSerial>0 and valorPorSerial<6)
    {
      Serial.print("Cant de requests: ");
      Serial.print(valorPorSerial);
      Serial.println();
      for (byte cont=0; cont<valorPorSerial; cont++){
        Serial.print(cont+1); Serial.print(": ");
        Serial.print("Requesting URL: "); Serial.println(url+data); 
        postReq(url, data, host);
      }
      Serial.println();
      valorPorSerial=0;
    }
  }

 // delay(10000);



  while(WIFI.available()){
    Serial.print("Respond:");
    String line = WIFI.readStringUntil('\r');
    Serial.println(line);

  }




} //End LOOP

//------------------------Funciones definidas por usuario----------------------------

String GetLineWIFI()
   {   String S = "" ;
       if (WIFI.available())
          {    char c = WIFI.read(); ;
                while ( c != '\n' )            //Hasta que el caracter sea intro
                  {     S = S + c ;
                        delay(25) ;
                        c = WIFI.read();
                   }
                 return( S ) ;
          }
   }


void postReq(String url, String data, String host) {
  WIFI.println(String("POST ") + url + " HTTP/1.0\r\n" +
              "Host: " + host + "\r\n" +
              "Accept: *" + "/" + "*\r\n" +
              "Content-Length: " + data.length() + "\r\n" +
              "Content-Type: application/x-www-form-urlencoded\r\n" +
              "\r\n" + data);
  }

void getReq(String url, String data, String host) {
  WIFI.println(String("GET ") + url + data + " HTTP/1.1\r\n" +
              "Host: " + host + "\r\n" +
              "Connection: close\r\n\r\n");
  }









