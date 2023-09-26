const int pinBoton = 12; // Pin GPIO donde está conectado el botón

volatile bool has_interruped = false;
void IRAM_ATTR miFuncionInterrupcion() {
  has_interrupted = true;
}

void setup() 
{
  Serial.begin(115200);
  pinMode(pinBoton, INPUT_PULLUP); // Configurar el pin como entrada con resistencia pull-up interna
  attachInterrupt(digitalPinToInterrupt(pinBoton), miFuncionInterrupcion, RISING); // Configurar la interrupción
}

void loop() 
{
  if(has_interrupted)
  {
    Serial.println("¡Botón presionado!");
    has_interrupted = false;
  }
}