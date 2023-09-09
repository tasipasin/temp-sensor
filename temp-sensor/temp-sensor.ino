#include <OneWire.h>
#include <DallasTemperature.h>

// O fio de dados é conectado no pino digital D4 no ESP
#define ONE_WIRE_BUS D4
// Índice do sensor
#define SENSOR_D4_INDEX 0
// Prepara uma instância oneWire para comunicar com qualquer outro dispositivo oneWire
OneWire oneWire(ONE_WIRE_BUS);
// Passa uma referência oneWire para a biblioteca DallasTemperature
DallasTemperature sensors(&oneWire);

float temperature = 0;

/**
* Realiza Setup inicial dos sensores de temperatura.
*/
void setupTempSensor(void){
  sensors.begin();
}

/**
* Retorna a temperatura, em ºC no index do sensor.
* @param index Indica o índice do sensor.
* @return Retorna a temperatura do sensor.
*/
float requestTemp(int index) {
  // Envia comando para ler temperaturas dos sensores
  sensors.requestTemperatures();
  // Retorna a temperatura no sensor contido no index
  return sensors.getTempCByIndex(index);
}

void setup(void) {
  Serial.begin(9600);
  
}
void loop(void) {
  float temperatureNow = requestTemp(SENSOR_D4_INDEX);
  if (temperature != temperatureNow) {
    temperature = temperatureNow;
    Serial.print("Temperatura: ");
    Serial.print(temperature);
    Serial.println(" graus");
  }
}