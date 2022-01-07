struct Animal{
  String family;
  int weight;
  String vore;
  String color;
  int age;
  boolean alive;
};

void setup() {
  Serial.begin(115200);
}

void loop() {
  struct Animal pig;
  pig.family = "hog";
  pig.weight = 200;
  pig.vore = "omnivore";
  pig.color = "pink";
  pig.age = 5;
  pig.alive = true;

  struct Animal monkey;
  monkey.family = "primate";
  monkey.weight = 70;
  monkey.vore = "herbivore";
  monkey.color = "brown";
  monkey.age = 12;
  monkey.alive = false;

 struct Animal bestAnimal = compareAnimal(&pig, &monkey);

  printAnimal(bestAnimal);
  delay(1000);

}

void printAnimal(struct Animal a){
  
  Serial.print("Family; ");
  Serial.println(a.family);
  
  Serial.print("Weight: ");
  Serial.println(a.weight);

  Serial.print("Vore: ");
  Serial.println(a.vore);

  Serial.print("Color: ");
  Serial.println(a.color);

  Serial.print("Age: ");
  Serial.println(a.age);

  Serial.print("Alive: ");
  Serial.println(a.alive);
  Serial.println("");
}

void swapMember(struct Animal *a, struct Animal *b){
  int temp = a->weight;
  a->weight = b->weight;
  b->weight = temp;
}

void swapMember2(struct Animal *a, struct Animal *b){
  String temp = a->vore;
  a->vore = b->vore;
  b->vore = temp;
}

Animal compareAnimal(struct Animal *a, struct Animal *b){
  struct Animal bestAnimal;
  if(a->weight> b->weight){ bestAnimal.weight = a->weight;
  }
  else bestAnimal.weight = b->weight;

  if(a->age> b->age){ bestAnimal.age = a->age;
  }
  else bestAnimal.age = b->age;

  if(a->alive || b->alive){ bestAnimal.alive = a->alive;
  }
  else bestAnimal.alive = false;
  bestAnimal.family = a->family;
  bestAnimal.vore = a->vore;
  bestAnimal.color = a->color;
  return bestAnimal;
}

//////////Questions//////////
//What is a member?
//A member is a variable that characterizes a struct. Another way to say it, is that a member variable is a variable that is associated with a specific object, and accessible for all its functions.

//Describe the difference between the four statements below:
//Answer:
//1. struct.member accesses the "member" variable when "struct" is given as a struct.
//2. *(struct).member accesses the member variable when struct is given as a pointer.
//3. *struct.member does the same thing as in 2
//4. struct->member accessess the member variable when struct is given as a pointer.

//When should struct be a pointer? When should member be a pointer?
//A struct should be a pointer when you want to modify the struct. That is, you want a method on "x" to modify "x".
//A member should be a pointer when you want to modify the member.