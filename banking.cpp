#include<iostream>
#include<string>
using namespace std;

//Description: class Bank that performs all basic operation of a bank.
class Bank{
    public:
       long long dollars;
       long long cents;

    public:
        // Constructor
        Bank(){
            dollars=0;
            cents=0;
        }

       void Deposit(long long d_dollars, long long d_cents){
           long long d_amount=d_dollars*100+d_cents;
           long long bal= dollars*100+cents;
           if(d_amount<0 && abs(d_amount)>bal) DepError();
           else{
                bal=bal+d_amount;
                dollars= bal/100;
                cents= bal%100;
                cout<<"Successful!"<<endl;
           }
       }  

       void Withdraw(long long w_dollars, long long w_cents){
           long long w_amount=w_dollars*100+w_cents;
           long long bal= dollars*100+cents;
           if(w_amount>bal)
           {
               WithdrawError();
           }
           else{
               bal=bal-w_amount;
               dollars= bal/100;
               cents= bal%100;
               cout<<"Done!"<<endl;
           }
       }

       void CheckBalance(){
           cout<<dollars<<"D"<<" "<<cents<<"C"<<endl;
       }

       //---------------------------------------------------------------------------------------
       // ERROR HANDLING
       void DepError(){
           cout<<"You don't have enough balance to perform this action"<<endl;
       }

       void WithdrawError()
       {
           cout<<"You don't have enough balance to withdraw this amount!"<<endl;
       }
};

//Description: for taking and processing the input.
long long inputBal()
{
    string val="";
    cout<<"Enter Amount: ";
    getline(cin, val);
    getline(cin, val);
    long long s=0;
    long long d_dol=0;
    long long d_cen=0;
    for(long long i=0;i<val.length();++i)
    {
        if(val[i]=='D') d_dol= stoi(val.substr(0,i));
        else if(val[i]==' ') s=i+1;
        else if(val[i]=='C') d_cen= stoi(val.substr(s, i-s));
    }
    return d_dol*100+d_cen;
}

//Description: Menu Driven approach for user long longerface
void BankingPortal(char ch, Bank &bank)
{
    switch(ch)
        {
            case '1':
            {
                long long dep = inputBal();
                bank.Deposit(dep/100, dep%100);
                break;
            }
            case '2':
            {
                long long withdraw= inputBal();
                bank.Withdraw(withdraw/100, withdraw%100);
                break;
            }
            case '3':
                bank.CheckBalance();
                break;    
            case '4':
                cout<<"Thank you!";
                break;    
            default:
                cout<<"Invalid Input!"<<endl;
                break;
        }
}

int main()
{
    char choice;
    Bank bank; // Creating object of Bank class, runs the constructor Bank()
    do{
        cout<<"Select a banking option:"<<endl;
        cout<<"1. Credit \n2. Debit \n3. Check Balance \n4. Quit"<<endl;
        cin>>choice;
        BankingPortal(choice, bank);
    }while(choice!='4');
    return 0;
}

