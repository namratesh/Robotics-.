/* Code Written by DPV TECHNOLOGY. WE have explained all the code in the grey comments.
we recommend you to go over the code, examine it, play with it, improve it and modify it according to your needs. 
SUBSCRIBE DPV TECHNOLOGY: 
https://www.youtube.com/dpvtechnology?sub_confirmation=1

*/
 
 #include <SoftwareSerial.h>

SoftwareSerial mySerial(15, 16);

void setup()
{
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  delay(100);
  mySerial.println("good");
}


void loop()
{
  if (Serial.available()>0)
   switch(Serial.read())
  {
    case 's':
      mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
     delay(1000);  // Delay of 1 second
     mySerial.println("AT+CMGS=\"+919981867769\"\r"); // Replace x with mobile number
     delay(1000);
     mySerial.println("Abnormal activity detected");// The SMS text you want to send
     delay(100);
     mySerial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
      delay(1000);
      break;



      
    case 'r':
      mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to receive a live SMS
      delay(1000);
      break;
  }

 if (mySerial.available()>0)
   Serial.write(mySerial.read());
}
