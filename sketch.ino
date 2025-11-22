

#include <LiquidCrystal.h>

const int ledVerde    = 2;
const int ledAmarelo  = 3;
const int ledVermelho = 4;
const int botao       = 7;


LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);

// Áreas profissionais e riscos (0=VERDE, 1=AMARELO, 2=VERMELHO)
const char* profissoes[] = {
  "Admin/Backoffic",
  "Desenv. Software",
  "Atend/Servicos",
  "Industria/Manuf",
  "Varejo/Comercio",
  "Ciencia Dados",
  "FinancasOper.",
  "Midia/Conteudo",
  "Logist/Transp.",
  "Enfermagem",
  "Agro Operacion.",
  "Manut/Serv.Tec.",
  "Juridico Oper.",
  "Saude Operacion"
};
const uint8_t risco[] = { 2, 0, 2, 1, 2, 0, 2, 1, 2, 0, 1, 1, 1, 0 };

int total = sizeof(profissoes) / sizeof(profissoes[0]);
int indiceAtual = 0;
unsigned long ultimaSelecao = 0;
const unsigned long debounceMs = 300;

void mostrarAtualLCD() {
  const char* p = profissoes[indiceAtual];
  uint8_t r = risco[indiceAtual];

  // LEDs
  digitalWrite(ledVerde,    r == 0 ? HIGH : LOW);
  digitalWrite(ledAmarelo,  r == 1 ? HIGH : LOW);
  digitalWrite(ledVermelho, r == 2 ? HIGH : LOW);

  // Monta texto de risco
  const char* riscoTxt;
  if (r == 0) {
    riscoTxt = "Baixo";
  } else if (r == 1) {
    riscoTxt = "Moderado";
  } else {
    riscoTxt = "Alto";
  }

  // Linha 1: profissão (até 16 chars)
  char linha1[17];
  strncpy(linha1, p, 16);
  linha1[16] = '\0';

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(linha1);

  lcd.setCursor(0, 1);
  lcd.print("Risco: ");
  lcd.print(riscoTxt);
}

void mostrarLegendaLCD() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Semaforo de");
  lcd.setCursor(0, 1);
  lcd.print("Empregabilidade");
  delay(2000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Verde=Baixo");
  lcd.setCursor(0, 1);
  lcd.print("Amarelo=Moderado");
  delay(2000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Vermelho=Alto");
  lcd.setCursor(0, 1);
  lcd.print("Pressione botao");
  delay(2000);
}

void setup() {
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(botao, INPUT_PULLUP);

  lcd.begin(16, 2);
  
  mostrarLegendaLCD();
  mostrarAtualLCD();
}

void loop() {
  // Botão pressionado = LOW (INPUT_PULLUP)
  if (digitalRead(botao) == LOW) {
    if (millis() - ultimaSelecao > debounceMs) {
      indiceAtual = (indiceAtual + 1) % total;
      mostrarAtualLCD();
      ultimaSelecao = millis();
    }
    // Aguarda soltar
    while (digitalRead(botao) == LOW) {
      delay(10);
    }
  }
  delay(10);
}