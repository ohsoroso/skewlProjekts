typedef struct {
  int month;
  int day;
  int year;
} DATE;

typedef struct {
  char name [25];
  char lName [25];
  DATE dob;
  char sex;
  float annIncome;
}person;