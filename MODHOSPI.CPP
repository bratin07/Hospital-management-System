#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>

struct patient
	{
	int p_id,age;
	char name[25],sex[8],bg[10],doa[25];
	long c_no;
	void Enter_details();
	void Show_details();
	void Assign_charges();
	void Assign_bed();
	void Assign_doctor();
	void Total_cost();
	char d_name[20];
	int b_no,r_no,f_no;
	int d_charge,m_charge,n_charge,f_charge,day,b_charge;
	int T_cost;
	int getid()
	{
	return p_id;
	}

	};

void patient::Assign_doctor()//assign doctor
	{
	int d_code;
	cout<<"		\n\nList of Doctors available are:-\n";
	cout<<"D_Code		D_Name		D_Field\n";
	cout<<" 101           Ravi Dubey       Cardiologist\n";
	cout<<" 102           P.Subramanium    Cardiologist\n";
	cout<<" 103           Prakash Raj      Orthopadics\n";
	cout<<" 104           Mahesh Pal       Orthopadics\n";
	cout<<" 105           K.P singh        Dermitologist\n";
	cout<<" 106           Ronit Roy        Dermitologist\n";
	cout<<" 107           Smrita Dey       Gaenacologist\n";
	cout<<" 108           Ranita Dutta     Gaenacologist\n";
	cout<<" 109           Swapna Singh     Neurologist\n";
	cout<<" 110           Rudra Ahuja      Neurologist\n";
	cout<<"\nEnter Doctor Code:-";
	cin>>d_code;
	if(d_code==101)
		strcpy(d_name,"Ravi Dubey");
	else if(d_code==102)
		strcpy(d_name,"P.Subramanium");
	else if(d_code==103)
		strcpy(d_name,"Prakash Raj");
	else if(d_code==104)
		strcpy(d_name,"Mahesh Pal");
	else if(d_code==105)
		strcpy(d_name,"K.P Singh");
	else if(d_code==106)
		strcpy(d_name,"Ronit Roy");
	else if(d_code==107)
		strcpy(d_name,"Smrita Dey");
	else if(d_code==108)
		strcpy(d_name,"Ranita Dutta");
	else if(d_code==109)
		strcpy(d_name,"Swapna Singh");
	else if(d_code==110)
		strcpy(d_name,"Rudra Ahuja");
	else
		{
		cout<<"\nWrong Code Entered" ;
		cout<<"\nDoctor not assigned";

		}
	}

void patient::Assign_bed()//Assign location of patient
	{
	cout<<"		\n\nEnter Location of Patient:-\n";
	cout<<"Enter Bed no.(1-10):-";
	cin>>b_no;
	cout<<"\nEnter Room no.(1-5):-";
	cin>>r_no;
	cout<<"\nEnter Floor no.(1-5):-";
	cin>>f_no;

	}



void patient::Assign_charges()//assign charges
	{
	cout<<"		\n\nEnter overall charges:-\n";
	cout<<"Enter Doctor fees:-";
	cin>>d_charge;
	cout<<"\nEnter Medicine charge:-";
	cin>>m_charge;
	cout<<"\nEnter Nurse Charge:-";
	cin>>n_charge;
	cout<<"\nEnter Canteen Charge:-";
	cin>>f_charge;
	cout<<"Enter no of days of stay:-";
	cin>>day;
	b_charge=(500*day);
	}

void patient::Total_cost()//Find total cost of the patient
	{
	int gst=0,cost=0;
	cost=(d_charge+m_charge+n_charge+f_charge+b_charge);
	gst=(10/100)*cost;
	T_cost=cost+gst;
	}





void patient::Enter_details() //enter details of patient
	{
	cout<<"\n\n             Enter Patient Details\n\n";
	cout<<"\nPatient ID:-";
	cin>>p_id;
	cout<<"\nName:-";
	gets(name);
	cout<<"\nAge:-";
	cin>>age;
	cout<<"\nSex:-";
	gets(sex);
	cout<<"\nBlood Group:-";
	gets(bg);
	cout<<"\nContact Number:-";
	cin>>c_no;
	cout<<"\nDate of Admit:-";
	gets(doa);
       Assign_doctor();
	Assign_bed();
	Assign_charges();
	Total_cost();
	clrscr();
	}


void patient::Show_details()
	{
	cout<<"\n\n             Patient Details \n\n";
	cout<<"\nPatient ID:-";
	cout<<p_id;
	cout<<"\nName:-";
	cout<<name;
	cout<<"\nAge:-";
	cout<<age;
	cout<<"\nSex:-";
	cout<<sex;
	cout<<"\nBlood Group:-";
	cout<<bg;
	cout<<"\nContact Number:-";
	cout<<c_no;
	cout<<"\nDate of Admit:-";
	cout<<doa;
	cout<<"\nDoctor Name:-";
	cout<<d_name;
	cout<<"\nBed No., Room No., Floor No.\n";
	cout<<"\t"<<b_no<<"\t"<<r_no<<"\t"<<f_no;
	cout<<"		\n\nOverall charges:-\n";
	cout<<" Doctor fees:-";
	cout<<d_charge;
	cout<<"\nMedicine charge:-";
	cout<<m_charge;
	cout<<"\nNurse Charge:-";
	cout<<n_charge;
	cout<<"\nCanteen Charge:-";
	cout<<f_charge;
	cout<<"\nNo of days of stay:-";
	cout<<day;
	cout<<"\nBed Charge :-";
	cout<<b_charge;
	cout<<"\n Total Cost :-";
	cout<<T_cost;
	}



void Insert()
{
	clrscr();
	char ch='y';
	int nop;//No of patients
	ofstream f("HOSPITAL.dat",ios::out|ios::app|ios::binary);
	patient P;
	while(ch=='y'||ch=='Y')
	{

	P.Enter_details();

	f.write((char*)&P,sizeof(P));

	cout<<"Do you want to add more records ....... ??\n";
	cin>>ch;
	}
	f.close();
}


void Display()
{

	ifstream f("HOSPITAL.dat",ios::in|ios::binary);
	patient P;
	if(!f)
	{
		cout<<"File not Found Sorry ";
		exit(0);
	}
	else
	{
		f.read((char*)&P, sizeof(P));
		while(!f.eof())
		{
			P.Show_details();
		       //	cout<<"\nPress Any Key....For Next Record "<<endl;
			getch();
			f.read((char*)&P, sizeof(P));
		}
	}
	f.close();
}






void DisplayP()		//Function to Display particular Record from Data File
{
	int id;
	cout<<"Enter ID that should be searched : ";
	cin>>id;
	ifstream f("HOSPITAL.dat",ios::in|ios::binary);
	patient P;
	if(!f)
	{
		cout<<"File not Found";
		exit(0);
	}
	else
	{
		f.read((char*)&P, sizeof(P));
		while(!f.eof())
		{
			if(id==P.getid())
			{
				P.Show_details();
			   //	cout<<"Press Any Key...."<<endl;
				getch();
			}
			else
			{
				 cout<<"Press Any Key....For Search"<<endl;
				 getch();
			}
			f.read((char*)&P, sizeof(P));
		}
	}
	f.close();
}




void Delete(int id)		//Function to Delete Particular Record from Data File
{

	ofstream o("new.dat",ios::out|ios::binary);
	ifstream f("HOSPITAL.dat",ios::in| ios::binary);
	patient P;
	if(!f)
	{
		cout<<"File not Found";
		exit(0);
	}
	else
	{
		f.read((char*)&P, sizeof(P));
		while(!f.eof())
		{
			if(P.p_id!=id)
			{
				o.write((char*)&P, sizeof(P));
			}
			else
			{
				 cout<<"Press Any Key....For Search"<<endl;
				 getch();
			}
			f.read((char*)&P, sizeof(P));
		}
	}
	o.close();
	f.close();
	remove("HOSPITAL.dat");
	rename("new.dat", "HOSPITAL.dat");
}//end of program



void Modify()
{
	int id;
	fstream f("HOSPITAL.dat",ios::in|ios::out|ios::app|ios::binary);
	int p=0;
	patient P;
	cout<<"\nEnter patient ID\n";
	cin>>id;
	while(f.read((char*)&P,sizeof(P)))
	{
	if(P.getid()==id)
	{
	cout<<"\n        Enter New Record...\n";
	P.Enter_details();
	f.seekg(p*sizeof(P),ios::beg);
	f.write((char*)&P,sizeof(P));
	}
	else
	{
	 cout<<"Press Any Key....For Search"<<endl;
	 getch();
	}

	p++;
	}
	f.close();
}







int main()
{
	int opt;
	clrscr();
	while(1)
	{
		clrscr();
		cout<<"		*   *  * * *  * * *      *        *   * * * *\n";
		cout<<"		*   *  *      *    *     *        *      *   \n";
		cout<<"		* * *  * * *  * * * *    *        *      *   \n";
		cout<<"		*   *  *      *      *   *        *      *   \n";
		cout<<"		*   *  * * *  *       *  * * *    *      *   \n";
		cout<<"		Caring for Lives......\n\n";
		cout<<"     	 MENU\n\n";
		cout<<"\t1.Insert Data File : "<<endl;
		cout<<"\t2.Display Record From Data File : "<<endl;
		cout<<"\t3.Display Particular Record From Data File : "<<endl;
		cout<<"\t4.Modify Paricular Record From Data File : "<<endl;
		cout<<"\t5.Delete Particular Record From Data File : "<<endl;
		cout<<"\t6.Exit From the Program : "<<endl;
		cout<<"\tEnter your Option -:";
		cin>>opt;
		switch(opt)
		{
			case 1:
			{
				Insert();
				cout<<" Display Main Menu "<<endl;
				getch();
				break;
			}
			case 2:
			{
				Display();
				cout<<" Display Main Menu "<<endl;
				getch();
				break;
			}
			case 3:
			{
				DisplayP();
				cout<<"Display Main Menu"<<endl;
				getch();
				break;
			}
			case 4:
			{
				Modify();
				cout<<"Display Main Menu"<<endl;
				getch();
				break;
			}
			case 5:
			{
				int id;
				cout<<"\nEnter the id to be deleted\n";
				cin>>id;
				Delete(id);
				cout<<"\n\n              ID "<<id<<" Deleted\n\n";
				cout<<"Display Main Menu"<<endl;
				getch();
				break;
			}
			case 6:
			{
				exit(0);
			}
			default:
			{
				cout<<"Wrong Choice....Press Key To View the Main Menu";
				getch();
				clrscr();
			}
		}
	}
}



