# Global-Solution-Edge-Computing-e-Computer-Systems
# Semáforo de Empregabilidade - IoT

## Sobre o Projeto

Protótipo IoT desenvolvido como parte do projeto **SkillShift** para visualizar o risco de automação em diferentes áreas profissionais. O dispositivo utiliza um sistema de semáforo (LEDs verde, amarelo e vermelho) e display LCD para comunicar de forma clara e intuitiva o nível de ameaça que a automação e inteligência artificial representam para cada profissão.

## Funcionalidades

- Sistema de LEDs que indica o nível de risco de automação por cores
- Display LCD 16x2 que exibe o nome da área profissional e classificação de risco
- Botão de navegação para alternar entre 14 áreas profissionais cadastradas
- Interface simples e intuitiva para conscientização sobre o futuro do trabalho

## Como Funciona

O usuário pressiona o botão para navegar entre as profissões. Para cada área selecionada:
- **LED Verde**: Baixo risco de automação
- **LED Amarelo**: Risco moderado de automação
- **LED Vermelho**: Alto risco de automação

O display LCD mostra simultaneamente o nome da profissão e o nível de risco detalhado.

## Componentes Utilizados

- Arduino Uno R3
- Display LCD 16x2
- 3 LEDs (Verde, Amarelo, Vermelho)
- 3 Resistores de 220Ω
- 1 Pushbutton
- Jumpers para conexões

## Áreas Profissionais Monitoradas

1. Administração e Backoffice
2. Desenvolvimento de Software
3. Atendimento e Serviços
4. Indústria e Manufatura
5. Varejo e Comércio
6. Ciência de Dados
7. Finanças Operacionais
8. Mídia e Conteúdo
9. Logística e Transporte
10. Enfermagem
11. Agronegócio Operacional
12. Manutenção e Serviços Técnicos
13. Jurídico Operacional
14. Saúde Operacional

## Tecnologias

- Linguagem: C++ (Arduino)
- Biblioteca: LiquidCrystal.h
- Plataforma de simulação: Wokwi

## Equipe

- **Gustavo Almeida Ferreira** - RM 566980
- **Lucas de Oliveira Miranda Caetano** - RM 568036
- **Sofia Souza Rodrigues** - RM 566708

## Contexto Educacional

Projeto desenvolvido para a disciplina de **Edge Computing & Computer Systems - IoT** como parte da Global Solution sobre requalificação profissional e o futuro do trabalho.

## Objetivo

Conscientizar trabalhadores sobre os impactos da automação no mercado de trabalho de forma visual, acessível e interativa, incentivando a busca por requalificação profissional.

## Instruções de Uso
## Simulação Online (Wokwi)

Acesse o link da simulação: Semáforo de Empregabilidade no Wokwi
Clique em "Start Simulation" para iniciar
Aguarde a tela de boas-vindas no LCD
Pressione o botão verde para navegar entre as profissões
Observe o LED correspondente acender e a informação no display LCD


## Arquivos do Projeto

sketch.ino - Código-fonte principal do Arduino 
diagram.json - Configuração do circuito para simulação no Wokwi
README.md - Documentação do projeto


## Protocolos de Comunicação
Este projeto utiliza comunicação digital simples entre Arduino e periféricos:

GPIO (General Purpose Input/Output): Comunicação direta com LEDs (saída digital) e botão (entrada digital com pull-up interno)
Protocolo Paralelo 4-bit: Comunicação com o display LCD usando 6 pinos (RS, E, D4, D5, D6, D7) para envio de comandos e dados
Pull-up interno: Botão configurado com INPUT_PULLUP para leitura estável sem necessidade de resistor externo

## Sobre MQTT e HTTP
O que são?

MQTT (Message Queuing Telemetry Transport): Protocolo de mensageria leve usado em IoT para comunicação entre dispositivos através de um broker central. Ideal para enviar dados de sensores para a nuvem ou receber comandos remotos.
HTTP (Hypertext Transfer Protocol): Protocolo padrão da web usado para requisições cliente-servidor. Em IoT, permite que dispositivos consumam APIs REST para buscar ou enviar dados pela internet.

## Por que este projeto NÃO utiliza MQTT/HTTP?
Este protótipo é um dispositivo standalone educacional que funciona de forma completamente independente, sem necessidade de conexão com internet ou servidores externos. Toda a lógica e dados estão embarcados no código Arduino.
Aplicação futura: Em uma versão conectada à internet (usando ESP32 ou módulo WiFi), poderíamos implementar:

MQTT para publicar estatísticas de uso e profissões mais consultadas em tempo real
HTTP para buscar atualizações da base de profissões de uma API REST remota

## Dependências

Arduino IDE 1.8.0 ou superior
Biblioteca LiquidCrystal.h (incluída nativamente no Arduino IDE)

Link da Simulação
🔗 https://wokwi.com/projects/448014990246792193
