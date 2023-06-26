#include <IRremote.h>
#include <LiquidCrystal.h>
#include <Servo.h>


/* CONTROL REMOTO */
#define IR_SENSOR 4
#define BOTON_ON_OF 0xFF00BF00

/*
#define BOTON_UNO 0xEF10BF00
#define BOTON_DOS 0xEE11BF00
#define BOTON_TRES 0xED12BF00
#define BOTON_CUATRO 0xEB14BF00
*/

/* LCD*/
#define RS 8
#define E 9
#define D4 10
#define D5 11
#define D6 12
#define D7 13

#define SENSOR_TEMP A0
#define SERVO 7

/* pines */
#define PIN_ROJO 2
#define PIN_VERDE 3

int temperatura = 0;
bool sistema_encendido = false;
String estacion = "";
bool incendio = false; 

LiquidCrystal lcd(RS, E, D4, D5, D6, D7); 

Servo miServo;

// C++ code


void setup()
{
  
  pinMode(2, OUTPUT);  
  pinMode(3, OUTPUT);
  
  lcd.begin(16,2);
  
  IrReceiver.begin(IR_SENSOR, DISABLE_LED_FEEDBACK); //Creo objeto del tipo IrReceiver
  //Recibe datos desde el módulo. Indico en qué pin tenemos conectado el receptor.
  
  miServo.attach(SERVO, 500, 2500);
  
  Serial.begin(9600);
  
}

void loop()
{
  
  DetectarControlRemoto();
  
  if(sistema_encendido)
  {
    int reading = analogRead(SENSOR_TEMP);
    temperatura = DefinirTemperatura(reading);
    DefinirEstacion(temperatura);
    DetectarIncendio();
    MostrarTextoLCD(temperatura);
    
    if (incendio){
      MoverServo(180);
      apagarLed(PIN_VERDE);
      titilarLedIncendio(PIN_ROJO, 3);    
    }
    
    else {
      prenderLed(PIN_VERDE);
      MoverServo(0); 
  	}
  }
  
  else {
    apagarLed(PIN_VERDE);
  }
  
  delay(500);
  lcd.clear();
  
}

void DetectarIncendio()
{
  if (temperatura > 60){
    incendio = true;
  }
  
  else {
    incendio = false;
  }
  
}

void MoverServo(int grados) {
  
  miServo.write(grados); 
  
}

void DetectarControlRemoto()
{

  if (IrReceiver.decode())  //Verifico si hay datos para decodificar (si se toco algun boton)
  {
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX); //Imprimo datos con valor Hexa
    
    if(IrReceiver.decodedIRData.decodedRawData == BOTON_ON_OF)
    {
      sistema_encendido = !sistema_encendido;
    }
    
    IrReceiver.resume(); //Preparo para recibir un nuevo codigo
    delay(100);
  }
  
}

float DefinirTemperatura(int reading) 
{
 
  Serial.print("Reading: ");  
  Serial.println(reading);
  
  float temp = map(reading, 20, 350, -40, 125);

  Serial.print("Temp: ");
  Serial.println(temp);
  
  /*
  float cuenta = 5.0 / 1024.0;
    
  float voltage = reading * cuenta;  
  
  // Convert the voltage into the temperature in Celsius
  // restamos 500mV porque 0°C = 0.5V

  float temperatureC = (voltage - 0.5) * 100;}
  */
  
  return temp;
}


void DefinirEstacion(int temperatura)
{
  
  if(temperatura < 0)
  {
    estacion = "INVIERNO";
  }
  else if (temperatura < 15){
    estacion = "OTONIO";
  }
  else if (temperatura < 35){
  	estacion = "PRIMAVERA";
  }
  else {
  	estacion = "VERANO";
  }
  
}

/*
void DefinirEstacion(long unsigned int num)
{
  
  switch(num){
    
    case BOTON_UNO:
    	estacion = "VERANO";
    	break;
    case BOTON_DOS:
    	estacion = "PRIMAVERA";
    	break;
    case BOTON_TRES: 
    	estacion = "OTONIO";
    	break;
    case BOTON_CUATRO:
    	estacion = "INVIERNO";
    	break;
    default:
    	estacion = "";
    	break;
  }
}

*/

void MostrarTextoLCD(float temp)
{
  
  if(incendio){
    lcd.setCursor(0,0);
    lcd.print("ALERTA INCENDIO");
  }
  
  else {
    lcd.setCursor(0,0);
    lcd.print(temp);
    lcd.setCursor(0,1);
    lcd.print(estacion);
  }
}


void prenderLed(int led)
{
  digitalWrite(led, HIGH);  
}

void apagarLed(int led)
{
  digitalWrite(led, LOW);  
}


void titilarLedIncendio(int pin_led, int veces)
{
  
  int contador = 0;
  apagarLed(pin_led);    
  delay(200);
  
  while (contador < veces)
  {
    prenderLed(pin_led);
    delay(300);
    apagarLed(pin_led);    
    delay(300);
    contador++;
  }
  
}

