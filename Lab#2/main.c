#include <stdlib.h>
#include <string.h>

typedef struct employee{
    int em_id;
    char em_name[10];
    int em_age;
    char em_phone[12];
    float em_salary;
} employee_t;

void employee_info(employee_t my_emp){
    printf("id: %d\n", my_emp.em_id);
    printf("name: %s\n", my_emp.em_name);
    printf("age: %d\n", my_emp.em_age);
    printf("phone: %s\n", my_emp.em_phone);
    printf("salary: %f\n", my_emp.em_salary);
    
}

int main()
{
    employee_t em;
    em.em_id = 1;
    strcpy(em.em_name, "LEE IU");
    em.em_age = 18;
    strcpy(em.em_phone, "0937123456");
    em.em_salary = 1000.30;
    employee_info (em);
    return 0;
}
