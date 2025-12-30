/*(Federal tax)-Develop a program that can be used to calculate the federal tax. The tax is
calculated as follows: For single people, the standard exemption is $4,000; for married people, the
standard exemption is $7,000. A person can also put up to 6% of his or her gross income in a
pension plan. The tax rates are as follows: If the taxable income is:
• Between $0 and $15,000, the tax rate is 15%.
• Between $15,001 and $40,000, the tax is $2,250 plus 25% of the taxable income over $15,000.
• Over $40,000, the tax is $8,460 plus 35% of the taxable income over $40,000.
Prompt the user to enter the following information:
• Marital status.
• If the marital status is ‘‘married,’’ ask for the number of children under the age of 14.
• Gross salary (If the marital status is ‘‘married’’ and both spouses have income, enter the combined
salary.)
• Percentage of gross income contributed to a pension fund.
Your program must consist of at least the following functions:
a. Function setData: This function asks the user to enter the relevant data.
b. Function taxAmount: This function computes and returns the tax owed.
To calculate the taxable income, subtract the sum of the standard exemption, the amount
contributed to a pension plan, and the personal exemption, which is $1,500 per person. (Note that if
a married couple has two children under the age of 14, then the personal exemption is $1,500 * 4 =
$6,000.)
Note: You should store these data( gross salary, pension contribution percentage, standard
exemption (based on material status), and total persons for personal exemptions (self or couple +
children) in 1D-array


____________________________________________________________________________________________________________________________________________________________________________________________
*/

#include <iostream>
using namespace std;
void setData(double allinfo[] , double &taxincome)
{
	string masi;
 	cout<<"\n-Are  you Married or Single ?"<<endl;
 	cin>>masi;
 	
 	if(masi=="married")
 	{
 
 	string un14;
 	cout<<"\n-Do you have a child under 14 years old ?(yes or no)"<<endl;
 	cin>>un14;
 	cout<<endl;
	if(un14=="yes")
	{
		
		int num1;
		cout<<"\n-How many children under 14 do you have ?"<<endl;
		cin>>num1;
		cout<<endl;
		allinfo[1]=(num1+2)*1500;
	}
	else{
		allinfo[1]=2*1500;
	}
	
 		allinfo[0]=7000;
	 }
	 else{
	 	allinfo[1]=1500;
		cout<<endl;
 		
 		allinfo[0]=4000;
	
	 }
 	
	
	double allin;
	cout<< "-How much is your total income (with your wifes, if she has any)?" <<endl;
	cin>>allin;
	cout<<endl;
	allinfo[2]=allin;
	
	double percent;
	cout<<"-What percentage do you pay into your pension plan ?(The maximum percentage of the pension plan is only 6%)"<<endl;
	cin>>percent;
	cout<<endl;
	allinfo[3]=percent;
			
	
	taxincome=(allinfo[2]*(allinfo[3]/100));
	taxincome=allinfo[2]-allinfo[0]-allinfo[1]-taxincome;
	
	cout<<"_________________________\n";
	cout<<"\nSo, your net taxable income =	 "<<taxincome<<endl;
}

//__________________________________________________________________________________________________________________________________________


double taxAmount(	double allinfo[] , double &taxincome)
{

	if(taxincome<=15000)
	{
		return taxincome*0.15;
	}
		else if(15000<taxincome&&taxincome<=40000)
	{
		return 2250+((taxincome-15000)*0.25);
	}
	else if(40000<taxincome)
	{
		return 8460+((taxincome-40000)*0.35);
	}
}

int main()
{
	
	string line(70,'*');
	string space(68,' ');
	cout<<line<<endl;
	cout<<"*"<<space<<"*"<<endl;
	cout<<"* NAME : AMER BASSAM ALSHLOUL * ID NUMBER : 202411391 * GROUP C      *"<<endl;
	cout<<"*"<<space<<"*"<<endl;
	cout<<line<<endl;
	
	
	double allinfo[4];
	double taxincome;
	cout<<"\n                        * WELCOME TO TAX CALCULATER *"<<endl;
	cout << "\n-We will ask you a few questions, and your tax amount will be calculated in just a few minutes!" << endl;
	cout<<"\n-Are you ready !(yes , no)"<<endl;
	string ready;
	cin>>ready;
	cout<<endl;
	if(ready=="yes")
	{
	
	setData(allinfo, taxincome);
cout <<"Federal tax you owe: " << taxAmount(allinfo, taxincome)<< endl;
cout<<"\nThank you for using our TAX CALCULATER !"<<endl;
}
else{
	cout<<"Let us know when you are ready. "<<endl;
	cout<<"Thank you for using our TAX CALCULATER ! "<<endl;
}



/* allinfo[0] = standard exemption
 allinfo[1] = personal exemption
 allinfo[2] = gross income
 allinfo[3] = pension percentage */





}

