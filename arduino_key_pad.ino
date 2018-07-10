//# Created by: Westley K
//# email: westley@sylabs.io
//# Date: Jul 10, 2018
//# Version-1.0
//# https://github.com/WestleyK/arduino-key-pad

/*
      keypad conection diagram

      1______2______3____row_0 to pin_5
      |      |      |
      |      |      |
      4______5______6____row_1 to pin_6
      |      |      |
      |      |      |
      7______8______9____row_2 to pin_7
      |      |      |
      |      |      |
      *______0______#____row_3 to pin_8
      |      |      |
      |      |      | 
    col_0  col_1  col_2
    pin_2  pin_3  pin_4
         to arduino:
*/


float start1 = 0;
float end1 = 0;
float time1 = 0;
String pass_code1 = "";
String pass_code2 = "";
int pass_up = 0;
float start10 = 0;
int col_0 = 2;
int col_1 = 3;
int col_2 = 4;
int row_0 = 5;
int row_1 = 6;
int row_2 = 7;
int row_3 = 8;


void setup() {
  Serial.begin(9600);
  pinMode(col_0, OUTPUT);
  pinMode(col_1, OUTPUT);
  pinMode(col_2, OUTPUT);
  digitalWrite(col_0, LOW);
  digitalWrite(col_1, LOW);
  digitalWrite(col_2, LOW);
  pinMode(row_0, INPUT_PULLUP);
  pinMode(row_1, INPUT_PULLUP);
  pinMode(row_2, INPUT_PULLUP);
  pinMode(row_3, INPUT_PULLUP);
}



char check_number() {
  digitalWrite(col_0, LOW);
  digitalWrite(col_1, HIGH);
  digitalWrite(col_2, HIGH);
  if (digitalRead(row_0) == LOW) {
    delay(150);
    while (digitalRead(row_0) == LOW) {
      if ((millis() - start10) >= 1000) {
        pass_code1 = "";
        pass_code2 = "";
        pass_up = 0;
        break;
      }
    }
    pass_up = 1;
    return '1';
  } else if (digitalRead(row_1) == LOW) {
    delay(150);
    while (digitalRead(row_1) == LOW) {
      if ((millis() - start10) >= 1000) {
        pass_code1 = "";
        pass_code2 = "";
        pass_up = 0;
        break;
      }
    }
    pass_up = 1;
    return '4';
  } else if (digitalRead(row_2) == LOW) {
    delay(150);
    while (digitalRead(row_2) == LOW) {
      if ((millis() - start10) >= 1000) {
        pass_code1 = "";
        pass_code2 = "";
        pass_up = 0;
        break;
      }
    }
    pass_up = 1;
    return '7';
  } else if (digitalRead(row_3) == LOW) {
    delay(150);
    while (digitalRead(row_3) == LOW) {
      if ((millis() - start10) >= 1000) {
        pass_code1 = "";
        pass_code2 = "";
        pass_up = 0;
        break;
      }
    }
    pass_up = 1;
    return 's'; // "s" stands for "*"
  }
  digitalWrite(col_0, HIGH);
  digitalWrite(col_1, LOW);
  digitalWrite(col_2, HIGH);
  if (digitalRead(row_0) == LOW) {
    delay(150);
    while (digitalRead(row_0) == LOW) {
      if ((millis() - start10) >= 1000) {
        pass_code1 = "";
        pass_code2 = "";
        pass_up = 0;
        break;
      }
    }
    pass_up = 1;
    return '2';
  } else if (digitalRead(row_1) == LOW) {
    delay(150);
    while (digitalRead(row_1) == LOW) {
      if ((millis() - start10) >= 1000) {
        pass_code1 = "";
        pass_code2 = "";
        pass_up = 0;
        break;
      }
    }
    pass_up = 1;
    return '5';
  } else if (digitalRead(row_2) == LOW) {
    delay(150);
    while (digitalRead(row_2) == LOW) {
      if ((millis() - start10) >= 1000) {
        pass_code1 = "";
        pass_code2 = "";
        pass_up = 0;
        break;
      }
    }
    pass_up = 1;
    return '8';
  } else if (digitalRead(row_3) == LOW) {
    delay(150);
    while (digitalRead(row_3) == LOW) {
      if ((millis() - start10) >= 1000) {
        pass_code1 = "";
        pass_code2 = "";
        pass_up = 0;
        break;
      }
    }
    pass_up = 1;
    return '0';
  }
  digitalWrite(col_0, HIGH);
  digitalWrite(col_1, HIGH);
  digitalWrite(col_2, LOW);
  if (digitalRead(row_0) == LOW) {
    delay(150);
    while (digitalRead(row_0) == LOW) {
      if ((millis() - start10) >= 1000) {
        pass_code1 = "";
        pass_code2 = "";
        pass_up = 0;
        break;
      }
    }
    pass_up = 1;
    return '3';
  } else if (digitalRead(row_1) == LOW) {
    delay(150);
    while (digitalRead(row_1) == LOW) {
      if ((millis() - start10) >= 1000) {
        pass_code1 = "";
        pass_code2 = "";
        pass_up = 0;
        break;
      }
    }
    pass_up = 1;
    return '6';
  } else if (digitalRead(row_2) == LOW) {
    delay(150);
    while (digitalRead(row_2) == LOW) {
      if ((millis() - start10) >= 1000) {
        pass_code1 = "";
        pass_code2 = "";
        pass_up = 0;
        break;
      }
    }
    pass_up = 1;
    return '9';
  } else if (digitalRead(row_3) == LOW) {
    delay(150);
    while (digitalRead(row_3) == LOW) {
      if ((millis() - start10) >= 1000) {
        pass_code1 = "";
        pass_code2 = "";
        pass_up = 0;
        break;
      }
    }
    pass_up = 1;
    return 'n'; // "n" stands for "#"
  }
  digitalWrite(col_2, HIGH);
}


void key_pad_read() {
  pass_code1 = check_number();
  if (pass_up == 1) {
    start10 = millis();
    pass_code2 += pass_code1;
    pass_up = 0;
  }
  Serial.println(pass_code2);
  delay(100);
  if (pass_code2 == "1234") {
    //# when correct code is entered
    code_true();
    Serial.println("correct code inputed");
    pass_code1 = "";
    pass_code2 = "";
  }
  //# if code is more the 4 character, reset
  if (pass_code2.length() >= 4) {
    pass_code1 = "";
    pass_code2 = "";
  }
  //# if there more than a 3 second wait between press, reset
  if ((millis() - start10) >= 3000) {
    pass_code1 = "";
    pass_code2 = "";
    pass_up = 0;
    Serial.println("Your too slow");
  }
}

//# do somthing when correct code is inputed
void code_true() {
  Serial.println("correct input");
}



void loop() {
  key_pad_read();
}



