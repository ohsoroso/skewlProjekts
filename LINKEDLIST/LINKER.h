typedef struct studentType {
  char name[30];
  int age;
  float weight;
  struct studentType *next;
}STUDENT;

typedef STUDENT *LIST;