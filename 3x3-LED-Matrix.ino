//MATRIX LED

// Upload this code to arduino and plug the wires in the matrix to see the action

char print[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Enter the string you want to print
//char print[] = "SOURAVBASU";
//char print[] = "A";

//GLOBALS
int i = 0;
int j = 0;
int k = 0;
int l = 0;

// Tinker with these variables to adjust the animation speed
int onTime = 50; 
int offTime = 500; 

int led[10][6] = {
  { 0, 1, 1, 1, 0, 0 },
  { 0, 1, 1, 0, 1, 0 },
  { 0, 1, 1, 0, 0, 1 },
  { 1, 0, 1, 1, 0, 0 },
  { 1, 0, 1, 0, 1, 0 },
  { 1, 0, 1, 0, 0, 1 },
  { 1, 1, 0, 1, 0, 0 },
  { 1, 1, 0, 0, 1, 0 },
  { 1, 1, 0, 0, 0, 1 },
};


int charArray[][3][3] = {
    { 
      { 0, 1, 0 }, //A
      { 1, 1, 1 }, 
      { 1, 0, 1 } 
    },
    {
      { 1, 1, 0 }, //B
      { 1, 1, 1 },
      { 1, 1, 0 }
    },
    {
      { 1, 1, 1 }, //C
      { 1, 0, 0 },
      { 1, 1, 1 }
    },
    {
      { 1, 1, 0 }, //D
      { 1, 0, 1 },
      { 1, 1, 0 }
    },
    {
      { 1, 1, 1 }, //E
      { 1, 1, 0 },
      { 1, 1, 1 }
    },
    {
      { 1, 1, 1 }, //F
      { 1, 1, 0 },
      { 1, 0, 0 }
    },
    {
      { 0, 1, 1 }, //G
      { 1, 1, 1 },
      { 0, 1, 1 }
    },
    {
      { 1, 0, 1 }, //H
      { 1, 1, 1 },
      { 1, 0, 1 }
    },
    {
      { 1, 1, 1 }, //I
      { 0, 1, 0 },
      { 1, 1, 1 }
    },
    {
      { 1, 1, 1 }, //J
      { 0, 1, 0 },
      { 1, 1, 0 }
    },
    {
      { 1, 0, 1 }, //K
      { 1, 1, 0 },
      { 1, 0, 1 }
    },
    {
      { 1, 0, 0 }, //L
      { 1, 0, 0 },
      { 1, 1, 1 }
    },
    {
      { 1, 1, 1 }, //M
      { 1, 1, 1 },
      { 1, 0, 1 }
    },
    {
      { 1, 0, 1 }, //N
      { 1, 1, 1 },
      { 1, 0, 1 }
    },
    {
      { 0, 1, 0 }, //N
      { 1, 0, 1 },
      { 0, 1, 0 }
    },
    {
      { 1, 1, 0 }, //P
      { 1, 1, 0 },
      { 1, 0, 0 }
    },
    {
      { 1, 1, 0 }, //Q
      { 1, 1, 0 },
      { 0, 0, 1 }
    },
    {
      { 1, 1, 0 }, //R
      { 1, 1, 0 },
      { 1, 0, 1 }
    },
    {
      { 1, 1, 0 }, //S
      { 1, 1, 1 },
      { 0, 1, 1 }
    },
    {
      { 1, 1, 1 }, //T
      { 0, 1, 0 },
      { 0, 1, 0 }
    },
    {
      { 1, 0, 1 }, //U
      { 1, 0, 1 },
      { 1, 1, 1 }
    },
    {
      { 1, 0, 1 }, //V
      { 1, 0, 1 },
      { 0, 1, 0 }
    },
    {
      { 1, 0, 1 }, //W
      { 1, 1, 1 },
      { 1, 0, 1 }
    },
    {
      { 1, 0, 1 }, //X
      { 0, 1, 0 },
      { 1, 0, 1 }
    },
    {
      { 1, 0, 1 }, //Y
      { 0, 1, 0 },
      { 0, 1, 0 }
    },
    {
      { 1, 1, 1 }, //Z
      { 0, 1, 0 },
      { 1, 1, 1 }
    },
};

void setup() {
  for(i = 5; i <= 10; i++)
    pinMode(i, OUTPUT);
  Serial.begin(9600);
}


void display(int character[3][3]) {

  for(l = 0; l < onTime; l++){
    k = 0;
    for(i = 0; i < 3; i++){
      for(j = 0; j < 3; j++){
        
        if(character[i][j]){
          //negatives
          digitalWrite(5, led[k][0]);
          digitalWrite(6, led[k][1]);
          digitalWrite(7, led[k][2]);
  
          //positives
          digitalWrite(8, led[k][3]);
          digitalWrite(9, led[k][4]);
          digitalWrite(10,led[k][5]);  
          
          delay(1);

          //Resetting Power Outputs
          digitalWrite(5, 1);
          digitalWrite(6, 1);
          digitalWrite(7, 1);
          
          digitalWrite(8, 0);
          digitalWrite(9, 0);
          digitalWrite(10,0);  
      
        } else{
          
          digitalWrite(5, 1);
          digitalWrite(6, 1);
          digitalWrite(7, 1);
  
          //positives
          digitalWrite(8, 0);
          digitalWrite(9, 0);
          digitalWrite(10,0);  
  
          delay(1);
              
        }
        k++;
      }
    }
  }     
}


void loop() {

  int index, m;
  
  for(index = 0; index < sizeof(print)/sizeof(char)-1; index++){
    Serial.println(print[index]);
    m = print[index]-65; // 65 is ASCII Stands for A
    Serial.println(m);
    display(charArray[m]);
    delay(offTime);
  }

}
