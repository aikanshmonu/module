#include <iostream>
using namespace std;


long long int HCF(long long int a, long long int b)
{
    if (a == 0)
        return b;
    return HCF(b % a, a);
}

long long int findHCF(long long int arr[], int n)
{
    long long int result = arr[0];
    for (int i = 1; i < n; i++)
    {
        result = HCF(arr[i], result);
 
        if(result == 1)
        {
           return 1;
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    int numOfTestCases;
    cin>>numOfTestCases;
    while(numOfTestCases-- != 0){
        int numOfEmployees;
        cin>>numOfEmployees;

        long long int salaryOfEmployees[numOfEmployees];
        int largestSalaryEmployeeIndex = 0;
        for(int i = 0; i < numOfEmployees; i++){
            cin>>salaryOfEmployees[i];
            if(salaryOfEmployees[i] > salaryOfEmployees[largestSalaryEmployeeIndex]){
                largestSalaryEmployeeIndex = i;
            }
        }

        long long int hcf = findHCF(salaryOfEmployees, numOfEmployees);

        long long int noOfNotes = 0;
        for(int i = 0; i < numOfEmployees; i++){
            if(i == largestSalaryEmployeeIndex){
                noOfNotes = noOfNotes + 1;
            }
            else{
                noOfNotes = noOfNotes + salaryOfEmployees[i] / hcf;
            }
        }
        cout<<noOfNotes<<endl;
    }
    return 0;
}
 