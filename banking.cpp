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

void BankingPortal(char ch, Bank &bank)
{
    switch(ch)
        {
            case '1':
            {
                string deposit_D;
                string deposit_C;
                cout<<"Enter Amount:"<<endl;
                cin>>deposit_D>>deposit_C;
                string dol="", cen="";
                int d_dollars=0, d_cents=0;
                dol=deposit_D.substr(0,deposit_D.length()-1);
                d_dollars=stoi(dol);
                cen=deposit_C.substr(0,deposit_C.length()-1);
                d_cents=stoi(cen);
                bank.Deposit(d_dollars+d_cents/100, d_cents%100);
                break;
            }
            case '2':
            {
                string withdraw_D;
                string withdraw_C;
                cout<<"Enter Amount:"<<endl;
                cin>>withdraw_D>>withdraw_C;
                string dol="", cen="";
                int w_dollars=0, w_cents=0;
                dol=withdraw_D.substr(0,withdraw_D.length()-1);
                w_dollars=stoi(dol);
                cen=withdraw_C.substr(0,withdraw_C.length()-1);
                w_cents=stoi(cen);
                bank.Withdraw(w_dollars+w_cents/100, w_cents%100);
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