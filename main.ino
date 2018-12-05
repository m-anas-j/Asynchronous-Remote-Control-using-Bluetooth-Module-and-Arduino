

int outputPin = 13;
char c;
String inString1 = "";
String inString2 = "";
int test1 = 0;
int test2 = 0;
unsigned long previousMillis = 0;
bool flag1 = true;
bool flag2 = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, 0);
}

void loop() {
  // put your main code here, to run repeatedly:

  //procedure for taking a string input and converting it to num value starts here
  unsigned long currentMillis = 0;
  inString1 = "";
  inString2 = "";
  while (Serial.available())
  {
    char inChar = Serial.read();
    if (isDigit(inChar))
    {
      Serial.println("Digit found");
      if (flag1)
      {
        inString1 += (char)inChar;
      }
      else
      {
        inString2 += (char)inChar;
      }
    }
    else if (inChar == ',')
    {
      Serial.println("Off value found");
      flag1 = false;
      //inString2 += (char)inChar;
      //Serial.println(inString2);
    }
    else
    {
      Serial.println("; found");
      test1 = inString1.toInt();
      test2 = inString2.toInt();
      Serial.println("On Value:");
      Serial.println(test1);
      Serial.println("On String:");
      Serial.println(inString1);
      Serial.println("Off Value:");
      Serial.println(test2);
      Serial.println("Off String:");
      Serial.println(inString2);
    }
    //test = test*10 + (int)(c-'0');
  }

  //procedure for taking a string input and converting it to num value ends here

  if (test1 != 0)
  {
    Serial.println("Delay started");
    digitalWrite(outputPin, HIGH);
    delay(test1 * 1000);
    Serial.println("Delay finished");
  }
  else
  {
    Serial.println("OFF");
    digitalWrite(outputPin, LOW);
  }
  while (test1 != 0)
  {

    inString1 = "";
    inString2 = "";
    while (Serial.available())
    {
      char inChar = Serial.read();
      if (isDigit(inChar))
      {
        Serial.println("Digit found");
        if (flag1)
        {
          inString1 += (char)inChar;
        }
        else
        {
          inString2 += (char)inChar;
        }
      }
      else if (inChar == ',')
      {
        Serial.println("Off value found");
        flag1 = false;
        //inString2 += (char)inChar;
        //Serial.println(inString2);
      }
      else
      {
        /*Serial.println("; found");
          Serial.println("Value:");
          test1 = inString.toInt();
          Serial.println(test);
          Serial.println("String:");
          Serial.println(inString);*/
        Serial.println("; found");
        test1 = inString1.toInt();
        test2 = inString2.toInt();
        Serial.println("On Value:");
        Serial.println(test1);
        Serial.println("On String:");
        Serial.println(inString1);
        Serial.println("Off Value:");
        Serial.println(test2);
        Serial.println("Off String:");
        Serial.println(inString2);
      }
    }
    flag1=true;

    Serial.print("ON for ");
    Serial.println(test1);
    digitalWrite(outputPin, HIGH);
    delay(test1 * 1000);
    Serial.print("OFF for ");
    Serial.println(test2);
    digitalWrite(outputPin, LOW);
    delay(test2 * 1000);
  }
}
