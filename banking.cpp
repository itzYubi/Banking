#include<iostream>
#include<string>
using namespace std;

class Bank{
    public:
       int dollars;
       int cents;

    public:
        Bank(){
            dollars=0;
            cents=0;
        }

       void Deposit(int d_dollars, int d_cents){
           int d_amount=d_dollars*100+d_cents;
           int bal= dollars*100+cents;
           if(d_amount<0 && abs(d_amount)>bal) WithdrawError();
           else{
                bal=bal+d_amount;
                dollars= bal/100;
                cents= bal%100;
                cout<<"Successful!"<<endl;
           }
       }  

       void Withdraw(int w_dollars, int w_cents){
           int w_amount=w_dollars*100+w_cents;
           int bal= dollars*100+cents;
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

       void WithdrawError()
       {
           cout<<"You don't have enough balance to withdraw this amount!"<<endl;
       }
};


int inputBal()
{
    string val="";
    cout<<"Enter Amount: ";
    getline(cin, val);
    getline(cin, val);
    int s=0;
    int d_dol=0;
    int d_cen=0;
    for(int i=0;i<val.length();++i)
    {
        if(val[i]=='D') d_dol= stoi(val.substr(0,i));
        else if(val[i]==' ') s=i;
        else if(val[i]=='C') d_cen= stoi(val.substr(s+1, i-s));
    }
    return d_dol*100+d_cen;
}

void BankingPortal(char ch, Bank &bank)
{
    switch(ch)
        {
            case '1':
            {
                int dep = inputBal();
                bank.Deposit(dep/100, dep%100);
                break;
            }
            case '2':
            {
                int withdraw= inputBal();
                bank.Withdraw(withdraw/100, withdraw%100);
                break;
            }
            case '3':
                bank.CheckBalance();
                break;    
            case '4':
                cout<<"Thank you";
                break;    
            default:
                cout<<"Invalid Input";
                break;
        }
}

int main()
{
    char choice;
    Bank bank;
    do{
        cout<<"Select a banking option:"<<endl;
        cout<<"1. Credit \n2. Debit \n3. Check Balance \n4. Quit"<<endl;
        cin>>choice;
        BankingPortal(choice, bank);
    }while(choice!='4');
    return 0;
}

