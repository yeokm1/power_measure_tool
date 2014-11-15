#include <Wire.h>
#include <SPI.h>
#include <Adafruit_INA219.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define POLL_RATE 200
#define SCREEN_RESET_PIN 4 //Digital 4
#define DISPLAY_CONTRAST true

Adafruit_INA219 ina219;
Adafruit_SSD1306 display(SCREEN_RESET_PIN);


void setup(void) 
{
  Serial.begin(115200);
  ina219.begin();

  // initialize with the OLED with I2C addr 0x3D (for the 128x64)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3D); 

  display.dim(DISPLAY_CONTRAST);

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0,0);  
  display.display();

}

void loop(void) 
{

  float outputVolt = ina219.getBusVoltage_V();
  float outputAmp = ina219.getCurrent_mA() / 1000;

  float outputWatt = outputVolt * outputAmp;

  float shuntVolt = ina219.getShuntVoltage_mV() / 1000;
  float sourceVolt = outputVolt + shuntVolt;


  display.clearDisplay();
  display.setCursor(0,0);  


  display.print("Out Power:   ");
  display.print(outputWatt, 3);
  display.println("W");
  
  display.println();

  display.print("Out Volt:    ");
  display.print(outputVolt, 3);
  display.println("V");
  
  display.println();
  
  display.print("Out Current: ");
  display.print(outputAmp, 4);
  display.println("A");
  
  display.println();

  display.print("Shunt Volt:  ");
  display.print(shuntVolt, 5);
  display.print("V");

  display.print("In Volt:     ");
  display.print(sourceVolt, 3);
  display.println("V");

  display.display();

  //Print order: outputWatt, outputVolt, outputAmp, shuntVolt, sourceVolt
  
  String output = "";
  char buff[10];
  
  String outputWattString = dtostrf(outputWatt, 0, 3, buff);
  output += outputWattString;
  output += " ";

  String outputVoltString = dtostrf(outputVolt, 0, 3, buff);
  output += outputVoltString;
  output += " ";
  
  String outputAmpString = dtostrf(outputVolt, 0, 4, buff);
  output += outputAmpString;
  output += " ";

  String shuntVoltString = dtostrf(shuntVolt, 0, 5, buff);
  output += shuntVoltString;
  output += " ";
  
  String sourceVoltString = dtostrf(sourceVolt, 0, 3, buff);
  output += sourceVoltString;
  
  Serial.println(output);
  Serial.flush();


  delay(POLL_RATE);
}




