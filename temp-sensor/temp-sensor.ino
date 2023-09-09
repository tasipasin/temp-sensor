#include <OneWire.h>
#include <DallasTemperature.h>

// O fio de dados é conectado no pino digital D4 no ESP
#define ONE_WIRE_BUS D4
#define SENSOR_D4_INDEX 0
// Prepara uma instância oneWire para comunicar com qualquer outro dispositivo oneWire
OneWire oneWire(ONE_WIRE_BUS);
// Passa uma referência oneWire para a biblioteca DallasTemperature
DallasTemperature sensors(&oneWire);

float temperature = 0;

float requestTemp(int index){
  sensors.requestTemperatures();
  return sensors.getTempCByIndex(index);
}

void setup(void) {
  Serial.begin(9600);
  sensors.begin();  // Inicia a biblioteca
}
void loop(void) {
  float temperatureNow = requestTemp(SENSOR_D4_INDEX);
  if (temperature != temperatureNow) {
    temperature = temperatureNow;
    // Manda comando para ler temperaturas
    // Escreve a temperatura em Celsius
    Serial.print("Temperatura: ");
    Serial.print(temperature);
    Serial.println(" graus");
  }
}