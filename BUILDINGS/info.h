typedef struct {
    int month;
    int day;
    int year;
} DATE;
typedef struct {
    char name[100];
    char lastName[100];
    DATE dob;
    char sex;
    float anualIncome;
} PERSON;