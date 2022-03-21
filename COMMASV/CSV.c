#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
 
// Driver Code
int main()
{
    // Substitute the full file path
    // for the string file_path
    FILE* fp = fopen("C:\\Users\\notfu\\Documents\\GitHub\\SkewlProjekts\\COMMASV\\student\\start\\2019-10-29-12.csv", "r");
 
    if (!fp)
        printf("Can't open file\n");
 
    else {
        // Here we have taken size of
        // array 1024 you can modify it
        char buffer[1024];
 
        int row = 0;
        int column = 0;
 
        while (fgets(buffer,
                     1024, fp)) {
            column = 0;
            row++;
 
            // Splitting the data
            char* value = strtok(buffer, ", ");
 
            while (value) {
                // Column 1
                if (column == 0) {
                    printf("Number :");
                }
 
                // Column 2
                if (column == 1) {
                    printf("\tMotor Number :");
                }
 
                // Column 3
                if (column == 2) {
                time_t     buffer;
                struct tm  ts;
                char       buf[80];

                // Format time, "ddd yyyy-mm-dd hh:mm:ss"
                ts = *localtime(&buffer);
                strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S %Z", &ts);
                    printf("\tTime :%s", buf);
                }

                // Column 4
                if (column == 3) {
                    printf("\tJunk :");
                }
 
                printf("%s", value);
                value = strtok(NULL, ", ");
                column++;
            }
 
            printf("\n");
        }
 
        // Close the file
        fclose(fp);
    }
    return 0;
}