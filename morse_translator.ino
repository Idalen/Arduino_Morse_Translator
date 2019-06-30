
/*Nesta parte inicial, declaramos 3 constantes fundamentais:
 * o tick, que determina a unidade básica de tempo do nosso sistema de tradução (nesse caso, 1 tick = 85 ms);
 * a freq, que contem a frequêcia a ser emitida pelo buzzer, que é de 800 Hz;
 * o Pin, que é a porta que utilizaremos no projeto.
 */
const int tick = 85;
const int freq = 800;
const int Pin = 13;


// Na função setup, iniciamos o monitor serial e definimos o Pin como output.

void setup() {
  Serial.begin(9600);
  pinMode(Pin, OUTPUT);
  Serial.println("Started!\n");
  
}

// A função loop é onde tudo é feito. 
void loop() {
  
  //A princípio, limitamos a execução do programa para apenas quando houver algo a ser lido no Serial. 
  if(Serial.available()> 0){    
          
      String Morse = "";           //Também declaramos a string que receberá as representações de cada char em morse
      char letra =Serial.read();   //além da função que lerá os char's.
          
      //No switch abaixo, há o alfabeto e sua tradução em morse, que será armazenada na variável Morse.
      switch(tolower(letra)) {
          case 'a': Morse = ".-";      break;
          case 'b': Morse = "-...";    break;  
          case 'c': Morse = "-.-.";    break;
          case 'd': Morse = "-..";     break;
          case 'e': Morse = ".";       break;
          case 'f': Morse = "..-.";    break;
          case 'g': Morse = "--.";     break;
          case 'h': Morse = "....";    break;
          case 'i': Morse = "..";      break;
          case 'j': Morse = ".---";    break;
          case 'k': Morse = "-.-";     break;
          case 'l': Morse = ".-..";    break;
          case 'm': Morse = "--";      break;
          case 'n': Morse = "-.";      break;
          case 'o': Morse = "---";     break;
          case 'p': Morse = ".--.";    break;
          case 'q': Morse = "--.-";    break;
          case 'r': Morse = ".-.";     break;
          case 's': Morse = "...";     break;
          case 't': Morse = "-";       break;
          case 'u': Morse = "..-";     break;
          case 'v': Morse = "...-";    break;
          case 'w': Morse = ".--";     break;
          case 'x': Morse = "-..-";    break;
          case 'y': Morse = "-.--";    break;
          case 'z': Morse = "--..";    break;
          case '1': Morse = ".----";   break;
          case '2': Morse = "..---";   break;
          case '3': Morse = "...--";   break;
          case '4': Morse = "....-";   break;
          case '5': Morse = ".....";   break;
          case '6': Morse = "-....";   break;
          case '7': Morse = "--...";   break;
          case '8': Morse = "---..";   break;
          case '9': Morse = "----.";   break;
          case '.': Morse = ".-.-.-";  break;
          case ',': Morse = "--..--";  break;
          case '?': Morse = "..--..";  break;
          case '!': Morse = "-.-.--";  break;
          case '/': Morse = "-..-.";   break;
          case '(': Morse = "-.--.";   break;
          case ')': Morse = "-.--.-";  break;
          case ';': Morse = "-.-.-.";  break;
          case ':': Morse = "---...";  break;
          case '"': Morse = ".-..-.";  break;
          default:  Morse = Morse + (" ");     break; //caso a entrada não esteja na lista, adicionamos uma função default
      }
      
    
    Serial.println(Morse);
    Morse = Morse + "s"; //e no final de cada string, adicionamos um char 's' para definir o fim de cada caractere
   
    /* 
     * No for abaixo, a expressão da linguagem será realizada.
     * Dependendo do valor do char da string, o buzzer e o led que utilizaremos emitirá uma resposta diferente:
     * para '.', eles emitirão um sinal mais curto, correspondente a um "dit";
     * para '-', um sinal mais longo, correspondente a um "dah";
     * e para 's', haverá uma curta pausa para indicar o fim do caractere.
     * Caso a leitura seja do espaço (ou de alguma caractere não reconhecido), haverá uma pausa um pouco mais demorada.
     */ 
    for (int i = 0; i < Morse.length(); i++) {
        switch(Morse[i]){
            case '.':
                digitalWrite(Pin, HIGH);
                tone(Pin, freq);
                delay(tick);
                digitalWrite(Pin, LOW);
                noTone(Pin); 
                delay(tick);
                break;
            case '-':
                digitalWrite(Pin, HIGH);
                tone(Pin, freq);
                delay(3*tick);
                analogWrite(Pin, LOW);
                noTone(Pin); 
                delay(tick);
                break;
            case 's':
                delay(3*tick);
                break;
            default: delay(4*tick); break;
        }    
      }
    }

}
