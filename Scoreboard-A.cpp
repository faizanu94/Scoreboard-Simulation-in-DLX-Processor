#include<iostream>
#include<sstream>
#include<stdio.h>
#include<conio.h>
#include<windows.h>
using namespace std;

struct InstructionStatus
{
	int Issue;
	int ReadOperand;
	int ExecutionComplete;
	int WriteResult;
	InstructionStatus()
	{
		Issue=0;
		ReadOperand=0;
		ExecutionComplete=0;
		WriteResult=0;
	}
};

struct FunctionalUnitStatus
{
	int FuNo;
	string Name;
	bool Busy;
	string Operand;
	string Destination;
	string Source1;
	string Source2;
	string FunctionalUnit1;
	string FunctionalUnit2;
	string Source1Ready;
	string Source2Ready;
	FunctionalUnitStatus()
	{
		FuNo=0;
		Name="";
		Busy=false;
		Operand="";
		Destination="";
		Source1="";
		Source2="";
		FunctionalUnit1="";
		FunctionalUnit2="";
		Source1Ready="Yes";
		Source2Ready="Yes";
	}
};

struct RegisterStatus
{
	string name;
	string value;
	RegisterStatus()
	{
		name="";
		value="";
	}
};

struct ExecutionCycle
{
	string Name;
	int cycles;
	ExecutionCycle()
	{
		Name="";
		cycles=0;
	}
};

InstructionStatus instructionstatus[6];
FunctionalUnitStatus functionalunitstatus[5];
RegisterStatus F[11];
ExecutionCycle executioncycle[5];
int numberofinstructions=7;
int numberoffunctionalunits=5;
int numberofregisters=11;
void gotoxy(int x,int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int Checker()
{
	int Flaggy=0;
	for(int m=0;m<6;m++)
	{
		if(instructionstatus[m].Issue == 0 || instructionstatus[m].ReadOperand == 0 || instructionstatus[m].ExecutionComplete == 0 || instructionstatus[m].WriteResult == 0)
			Flaggy=1;
	}
	return Flaggy;
}

int main()
{
	system("mode 76,42");
	system("color 4F");
	int checker;
	int checker1;
	int funcu;
	int funcu1;
	int donotwrite;
	int Type;
	int Destination;
	int Source1;
	int Source2;
	int used;
	int u;
	int i;
	int Now;
	int registerupdate;
	int IterationNumber;
	int InstructionNumber;
	double doubletypecaster;
	string data1;
	string data2;
	bool Flag;
	bool Allow;
	std::string str;
	checker=0;
	checker1=0;
	funcu=0;
	funcu1=0;
	donotwrite=0;
	IterationNumber=1;
	Type=0;
	Destination=1;
	Source1=2;
	Source2=3;
	InstructionNumber=0;
	Flag=false;
	Allow=true;
	string Instruction[7];
	Instruction[0]="LD F6,34(R2)";
	Instruction[1]="LD F2,45(R3)";
	Instruction[2]="MUL F0,F2,F4";
	Instruction[3]="SUB F8,F6,F2";
	Instruction[4]="DIV F10,F0,F6";
	Instruction[5]="ADD F6,F8,F2";
	Instruction[6]="BNEZ R1 Loop";
	string InstructionDetails[7][5];
	InstructionDetails[0][0]="LDSD";
	InstructionDetails[0][1]="F6";
	InstructionDetails[0][2]="R2";
	InstructionDetails[0][3]="";
	InstructionDetails[0][4]="";
	InstructionDetails[1][0]="LDSD";
	InstructionDetails[1][1]="F2";
	InstructionDetails[1][2]="R3";
	InstructionDetails[1][3]="";
	InstructionDetails[1][4]="";
	InstructionDetails[2][0]="MUL0";
	InstructionDetails[2][1]="F0";
	InstructionDetails[2][2]="F2";
	InstructionDetails[2][3]="F4";
	InstructionDetails[2][4]="";
	InstructionDetails[3][0]="ADDD";
	InstructionDetails[3][1]="F8";
	InstructionDetails[3][2]="F6";
	InstructionDetails[3][3]="F2";
	InstructionDetails[3][4]="";
	InstructionDetails[4][0]="DIV";
	InstructionDetails[4][1]="F10";
	InstructionDetails[4][2]="F0";
	InstructionDetails[4][3]="F6";
	InstructionDetails[4][4]="";
	InstructionDetails[5][0]="ADDD";
	InstructionDetails[5][1]="F6";
	InstructionDetails[5][2]="F8";
	InstructionDetails[5][3]="F2";
	InstructionDetails[5][4]="";
	InstructionDetails[6][0]="BNEZ";
	InstructionDetails[6][1]="R1";
	InstructionDetails[6][2]="";
	InstructionDetails[6][3]="";
	InstructionDetails[6][4]="";
	string RegisterValues[9][2];
	RegisterValues[0][0]="R1";
	RegisterValues[0][1]="0";
	RegisterValues[1][0]="R2";
	RegisterValues[1][1]="8";
	RegisterValues[2][0]="R3";
	RegisterValues[2][1]="6";
	RegisterValues[3][0]="F0";
	RegisterValues[3][1]="";
	RegisterValues[4][0]="F2";
	RegisterValues[4][1]="";
	RegisterValues[5][0]="F4";
	RegisterValues[5][1]="4";
	RegisterValues[6][0]="F6";
	RegisterValues[6][1]="";
	RegisterValues[7][0]="F8";
	RegisterValues[7][1]="";
	RegisterValues[8][0]="F10";
	RegisterValues[8][1]="";
	functionalunitstatus[0].Name="LDSD";
	functionalunitstatus[1].Name="ADDD";
	functionalunitstatus[2].Name="DIV";
	functionalunitstatus[3].Name="MUL0";
	functionalunitstatus[4].Name="MUL1";
	executioncycle[0].Name="LDSD";
	executioncycle[1].Name="ADDD";
	executioncycle[2].Name="DIV";
	executioncycle[3].Name="MUL0";
	executioncycle[4].Name="MUL1";
	F[0].name="F0";
	F[1].name="F1";
	F[2].name="F2";
	F[3].name="F3";
	F[4].name="F4";
	F[5].name="F5";
	F[6].name="F6";
	F[7].name="F7";
	F[8].name="F8";
	F[9].name="F9";
	F[10].name="F10";
	jump:
	while(Checker()!=0)
	{
		for(Now=InstructionNumber;Now>=0;Now--)
		{
			//---------------------------------------------ISSUE BEGIN---------------------------------------------//
			if(Flag == false && instructionstatus[Now].Issue==0)
			{
				for(u=0;u<numberoffunctionalunits;u++)
				{
					if(InstructionDetails[Now][Type]==functionalunitstatus[u].Name)
					{
						if(functionalunitstatus[u].Busy==false)
						{
							for(int Destinationcheck=0;Destinationcheck<Now;Destinationcheck++)
							{	
								if(InstructionDetails[Now][Destination]==InstructionDetails[Destinationcheck][Destination])
								{
									if(instructionstatus[Destinationcheck].WriteResult==0)
									{
										Allow=false;		
									}	
								}	
							}
							if(Allow==true)
							{
								functionalunitstatus[u].Busy=true;
								for(used=0;used<numberofregisters;used++)
								{
									if(InstructionDetails[Now][1]==F[used].name)
									{
										F[used].value=InstructionDetails[Now][Type];
										break;
									}
								}
								functionalunitstatus[u].Operand=InstructionDetails[Now][Type];
								functionalunitstatus[u].Destination=InstructionDetails[Now][1];
								instructionstatus[Now].Issue=IterationNumber;
								InstructionNumber++;
								if(InstructionDetails[Now][Type]=="ADDD" || InstructionDetails[Now][Type]=="DIV" || InstructionDetails[Now][Type]=="MUL0" || InstructionDetails[Now][Type]=="MUL1")
								{
									functionalunitstatus[u].Source1=InstructionDetails[Now][2];
									functionalunitstatus[u].Source2=InstructionDetails[Now][3];
									for(used=0;used<numberofregisters;used++)
									{
										if(F[used].name==functionalunitstatus[u].Source1)
										{
											if(F[used].value=="")
												functionalunitstatus[u].Source1Ready="Yes";
											else
												functionalunitstatus[u].Source1Ready="No";
											functionalunitstatus[u].FunctionalUnit1=F[used].value;
										}
										if(F[used].name==functionalunitstatus[u].Source2)
										{
											if(F[used].value=="")
												functionalunitstatus[u].Source2Ready="Yes";
											else
												functionalunitstatus[u].Source2Ready="No";
											functionalunitstatus[u].FunctionalUnit2=F[used].value;
										}
									}
								}
								else if(InstructionDetails[Now][Type]=="LDSD")
								{
									functionalunitstatus[u].Source1=InstructionDetails[Now][2];
									for(used=0;used<numberofregisters;used++)
									{
										if(F[used].name==functionalunitstatus[u].Source1)
										{
											if(F[used].value=="")
												functionalunitstatus[u].Source1Ready="Yes";
											else
												functionalunitstatus[u].Source1Ready="No";
											functionalunitstatus[u].FunctionalUnit1=F[used].value;
										}
									}
								}
								Flag=true;
								break;
							}
						}
					}
				}
			}
			//---------------------------------------------ISSUE END---------------------------------------------//

			//----------------------------------------READ OPERAND BEGIN----------------------------------------//
			Allow=true;	
			if(Flag==false && instructionstatus[Now].Issue!=0 && instructionstatus[Now].ReadOperand==0 )
			{
				if(InstructionDetails[Now][Type]=="ADDD" || InstructionDetails[Now][Type]=="DIV" || InstructionDetails[Now][Type]=="MUL0" || InstructionDetails[Now][Type]=="MUL1")
				{
					for(int Destinationcheck=0;Destinationcheck<Now;Destinationcheck++)
					{
							if(InstructionDetails[Now][Source1]==InstructionDetails[Destinationcheck][Destination]|| InstructionDetails[Now][Source2]==InstructionDetails[Destinationcheck][Destination])
							{
								if(instructionstatus[Destinationcheck].WriteResult==0)
								{
									Allow=false;		
								}
							}
					}
					if(Allow==false){
						for(int Destinationcheck=0;Destinationcheck<Now;Destinationcheck++)
						{	
							if(InstructionDetails[Now][Source1]==InstructionDetails[Destinationcheck][Destination])
							{
								if(instructionstatus[Destinationcheck].WriteResult==0)
								{
									Allow=false;		
								}
								else{
									for(used=0;used<numberoffunctionalunits;used++)
									{			
										if(functionalunitstatus[used].Destination==InstructionDetails[Now][1])
										{
											functionalunitstatus[used].FunctionalUnit1=" ";
										}
									}
								}
							}
							if(InstructionDetails[Now][Source2]==InstructionDetails[Destinationcheck][Destination])
							{
								if(instructionstatus[Destinationcheck].WriteResult==0)
								{
									Allow=false;		
								}
								else{
									for(used=0;used<numberoffunctionalunits;used++)
									{			
										if(functionalunitstatus[used].Destination==InstructionDetails[Now][1])
										{
											functionalunitstatus[used].FunctionalUnit2=" ";
										}
									}
								}
							}
						}	
					}
					if(Allow==true)
					{
						instructionstatus[Now].ReadOperand=IterationNumber;
						for(used=0;used<numberoffunctionalunits;used++)
						{
							if(functionalunitstatus[used].Destination==InstructionDetails[Now][1])
							{
								functionalunitstatus[used].FunctionalUnit1=" ";
								functionalunitstatus[used].FunctionalUnit2=" ";
							}
						}
						Flag=true;
					}
				}
				else if(InstructionDetails[Now][Type]=="LDSD")
				{
					for(int Destinationcheck=0;Destinationcheck<numberoffunctionalunits;Destinationcheck++)
					{
						if(InstructionDetails[Now][Source1]==InstructionDetails[Destinationcheck][Destination])
						{
								if(instructionstatus[Destinationcheck].WriteResult==0)
								{
									Allow=false;		
								}
							}
					}
					if(Allow==true)
					{
						instructionstatus[Now].ReadOperand=IterationNumber;
						for(used=0;used<numberoffunctionalunits;used++)
						{
							if(functionalunitstatus[used].Destination==InstructionDetails[Now][1])
							{
								functionalunitstatus[used].FunctionalUnit1=" ";
							}
						}
						Flag=true;
					}
				}
			}
			//----------------------------------------READ OPERAND END----------------------------------------//
			//----------------------------------------EXECUTION BEGIN----------------------------------------//
			Allow=true;	
			if(Flag==false&&instructionstatus[Now].Issue!=0 && instructionstatus[Now].ReadOperand!=0 && instructionstatus[Now].ExecutionComplete==0)
			{
				for(int ex=0;ex<numberoffunctionalunits;ex++)
				{
					if(executioncycle[ex].Name==InstructionDetails[Now][Type])
					{
						executioncycle[ex].cycles=executioncycle[ex].cycles+1;
						if(InstructionDetails[Now][Type]=="ADDD")
						{
							if(executioncycle[ex].cycles==2)
							{
								instructionstatus[Now].ExecutionComplete=IterationNumber;
								Flag=true;
								break;
							}
						}
						else if(InstructionDetails[Now][Type]=="LDSD")
						{
							if(executioncycle[ex].cycles==1)
							{
								instructionstatus[Now].ExecutionComplete=IterationNumber;
								Flag=true;
								break;
							}
						}
						else if(InstructionDetails[Now][Type]=="DIV")
						{
							if(executioncycle[ex].cycles==40)
							{
								instructionstatus[Now].ExecutionComplete=IterationNumber;
								Flag=true;
								break;
							}
						}
						else if(InstructionDetails[Now][Type]=="MUL0")
						{
							if(executioncycle[ex].cycles==10)
							{
								instructionstatus[Now].ExecutionComplete=IterationNumber;
								Flag=true;
								break;
							}
						}
						else if(InstructionDetails[Now][Type]=="MUL1")
						{
							if(executioncycle[ex].cycles==10)
							{
								instructionstatus[Now].ExecutionComplete=IterationNumber;
								Flag=true;
								break;
							}
						}
					}
				}
			}
			//----------------------------------------EXECUTION END----------------------------------------//
			//--------------------------------------WRITE BACK BEGIN--------------------------------------//
			Allow=true;	
			if(Flag==false&&instructionstatus[Now].Issue!=0&&instructionstatus[Now].ReadOperand!=0&&instructionstatus[Now].ExecutionComplete!=0&&instructionstatus[Now].WriteResult==0)
			{
				for(int Destinationcheck=0;Destinationcheck<Now;Destinationcheck++)
				{
					if(InstructionDetails[Now][Destination]==InstructionDetails[Destinationcheck][Source1]||InstructionDetails[Now][Destination]==InstructionDetails[Destinationcheck][Source2])
					{
						if(instructionstatus[Destinationcheck].ReadOperand==0)
						{
							Allow=false;
						}
					}	
				}
				if(Allow==true)
				{
					instructionstatus[Now].WriteResult=IterationNumber;
					for(int u=0;u<numberoffunctionalunits;u++)
					{
						if(InstructionDetails[Now][Type]==functionalunitstatus[u].Name)
						{
							checker++;
							funcu=u;
						}
						if(InstructionDetails[Now][Type]==executioncycle[u].Name)
						{
							checker1++;
							funcu1=u;	
						}
					}
				}
				if(InstructionDetails[Now][Type]=="LDSD")
				{
					for(registerupdate=0;registerupdate<9;registerupdate++)
					{
						if(InstructionDetails[Now][Source1] == RegisterValues[registerupdate][0] && RegisterValues[registerupdate][1]!="")
							data1 = RegisterValues[registerupdate][1];
					}
					for(registerupdate=0;registerupdate<9;registerupdate++)
					{
						if(InstructionDetails[Now][Destination]==RegisterValues[registerupdate][0])
							RegisterValues[registerupdate][1] = data1;
					}
				}
				if(InstructionDetails[Now][Type]=="ADDD")
				{
					for(registerupdate=0;registerupdate<9;registerupdate++)
					{
						if(InstructionDetails[Now][Source1] == RegisterValues[registerupdate][0] && RegisterValues[registerupdate][1]!="")
							data1 = RegisterValues[registerupdate][1];
						if(InstructionDetails[Now][Source2] == RegisterValues[registerupdate][0] && RegisterValues[registerupdate][1]!="")
							data2 = RegisterValues[registerupdate][1];
						if(InstructionDetails[Now][Destination]=="F6")
						{
							doubletypecaster = strtod(data1.c_str(),NULL)+strtod(data2.c_str(),NULL);
						}
						if(InstructionDetails[Now][Destination]=="F8")
						{
							doubletypecaster = strtod(data1.c_str(),NULL)-strtod(data2.c_str(),NULL);
						}
						stringstream strs;
						strs << doubletypecaster;
						str = strs.str();
					}
					for(registerupdate=0;registerupdate<9;registerupdate++)
					{
						if(InstructionDetails[Now][Destination]==RegisterValues[registerupdate][0] && str!="")
							RegisterValues[registerupdate][1] = str;
					}
				}
				if(InstructionDetails[Now][Type]=="DIV")
				{
					for(registerupdate=0;registerupdate<9;registerupdate++)
					{
						if(InstructionDetails[Now][Source1] == RegisterValues[registerupdate][0] && RegisterValues[registerupdate][1]!="")
							data1 = RegisterValues[registerupdate][1];
						if(InstructionDetails[Now][Source2] == RegisterValues[registerupdate][0] && RegisterValues[registerupdate][1]!="")
							data2 = RegisterValues[registerupdate][1];
						doubletypecaster = strtod(data1.c_str(),NULL)/strtod(data2.c_str(),NULL);
						stringstream strs;
						strs << doubletypecaster;
						str = strs.str();
					}
					for(registerupdate=0;registerupdate<9;registerupdate++)
					{
						if(InstructionDetails[Now][Destination]==RegisterValues[registerupdate][0] && str!="")
							RegisterValues[registerupdate][1] = str;
					}
				}
				if(InstructionDetails[Now][Type]=="MUL0")
				{
					for(registerupdate=0;registerupdate<9;registerupdate++)
					{
						if(InstructionDetails[Now][Source1] == RegisterValues[registerupdate][0] && RegisterValues[registerupdate][1]!="")
							data1 = RegisterValues[registerupdate][1];
						if(InstructionDetails[Now][Source2] == RegisterValues[registerupdate][0] && RegisterValues[registerupdate][1]!="")
							data2 = RegisterValues[registerupdate][1];
						doubletypecaster = strtod(data1.c_str(),NULL)*strtod(data2.c_str(),NULL);
						stringstream strs;
						strs << doubletypecaster;
						str = strs.str();
					}
					for(registerupdate=0;registerupdate<9;registerupdate++)
					{
						if(InstructionDetails[Now][Destination]==RegisterValues[registerupdate][0] && str!="")
							RegisterValues[registerupdate][1] = str;
					}
				}
				if(InstructionDetails[Now][Type]=="MUL1")
				{
					for(registerupdate=0;registerupdate<9;registerupdate++)
					{
						if(InstructionDetails[Now][Source1] == RegisterValues[registerupdate][0] && RegisterValues[registerupdate][1]!="")
							data1 = RegisterValues[registerupdate][1];
						if(InstructionDetails[Now][Source2] == RegisterValues[registerupdate][0] && RegisterValues[registerupdate][1]!="")
							data2 = RegisterValues[registerupdate][1];
						doubletypecaster = strtod(data1.c_str(),NULL)*strtod(data2.c_str(),NULL);
						stringstream strs;
						strs << doubletypecaster;
						str = strs.str();
					}
					for(registerupdate=0;registerupdate<9;registerupdate++)
					{
						if(InstructionDetails[Now][Destination]==RegisterValues[registerupdate][0] && str!="")
							RegisterValues[registerupdate][1] = str;
					}
				}
			}
			Flag=false;
			Allow=true;
			//--------------------------------------WRITE BACK END--------------------------------------//
		}
		if(checker>0)
		{
			functionalunitstatus[funcu].Busy=false;
			functionalunitstatus[funcu].Source1="";
			functionalunitstatus[funcu].Source2="";
			functionalunitstatus[funcu].Operand="";
			for(used=0;used<numberofregisters;used++)
			{
				if(F[used].name==functionalunitstatus[funcu].Destination)
				{
					F[used].value="";
					break;
				}
			}
			for(used=0;used<numberoffunctionalunits;used++)
			{
				functionalunitstatus[used].Source1Ready="";
				functionalunitstatus[used].Source2Ready="";
			}
			functionalunitstatus[funcu].Destination="";
			checker=0;
			funcu=0;
		}
		if(checker1>0)
		{
			executioncycle[funcu1].cycles=0;
			checker1=0;
			funcu1=0;
		}
		IterationNumber++;
		cout<<"Instruction"<<"       Issue"<<"	 Read Operand"<<"	Execution Complete"<<"	Write Result"<<endl;
		int x1=0;
		int y1=2;
		for(int i=0;i<numberofinstructions;i++)
		{
			gotoxy(x1,y1);
			cout<<Instruction[i];
			x1+=20;
			gotoxy(x1,y1);
			if(instructionstatus[i].Issue>0 && instructionstatus[i].Issue<1000)
				cout<<instructionstatus[i].Issue;
			x1+=10;
			gotoxy(x1,y1);
			if(instructionstatus[i].ReadOperand>0 && instructionstatus[i].ReadOperand<1000)
				cout<<instructionstatus[i].ReadOperand;
			x1+=20;
			gotoxy(x1,y1);
			if(instructionstatus[i].ExecutionComplete>0 && instructionstatus[i].ExecutionComplete<1000)
				cout<<instructionstatus[i].ExecutionComplete;
			x1+=20;
			gotoxy(x1,y1);
			if(instructionstatus[i].WriteResult>0 && instructionstatus[i].WriteResult<1000)
				cout<<instructionstatus[i].WriteResult;
			x1=0;
			y1+=2;
		}
		gotoxy(0,y1+1);
		cout<<"Name"<<"	 Busy"<<"	Op"<<"   Dest"<<" Src1"<<"	Src2"<<"	FU1"<<"    FU2"<<"    Src1Rdy"<<"	Src2Rdy"<<endl<<endl;
		x1=0;
		y1=19;
		for(int i=0;i<numberoffunctionalunits;i++)
		{
			gotoxy(x1,y1);
			cout<<functionalunitstatus[i].Name;
			x1+=10;
			gotoxy(x1,y1);
			if(functionalunitstatus[i].Busy==0)
				cout<<"No";
			if(functionalunitstatus[i].Busy==1)
				cout<<"Yes";
			x1+=5;
			gotoxy(x1,y1);
			cout<<functionalunitstatus[i].Operand;
			x1+=6;
			gotoxy(x1,y1);
			cout<<functionalunitstatus[i].Destination;
			x1+=6;
			gotoxy(x1,y1);
			cout<<functionalunitstatus[i].Source1;
			x1+=6;
			gotoxy(x1,y1);
			cout<<functionalunitstatus[i].Source2;
			x1+=7;
			gotoxy(x1,y1);
			cout<<functionalunitstatus[i].FunctionalUnit1;
			x1+=7;
			gotoxy(x1,y1);
			cout<<functionalunitstatus[i].FunctionalUnit2;
			x1+=8;
			gotoxy(x1,y1);
			cout<<functionalunitstatus[i].Source1Ready;
			x1+=10;
			gotoxy(x1,y1);
			cout<<functionalunitstatus[i].Source2Ready;
			x1=0;
			y1+=2;
		}
		gotoxy(0,y1+1);
		cout<<"F0"<<"     F1"<<"     F2"<<"     F3"<<"     F4"<<"     F5"<<"     F6"<<"     F7"<<"     F8"<<"     F9"<<"     F10"<<endl;
		x1=0;
		y1=32;
		for(int i=0;i<numberofregisters;i++)
		{
			gotoxy(x1,y1);
			cout<<F[i].value;
			x1+=7;
		}
		Sleep(100);
		if(Checker()!=0)
			system("cls");
		Now=6;
	}
	if(InstructionDetails[Now][Type]=="BNEZ")
	{
		if(RegisterValues[0][1]=="0")
		{
			RegisterValues[0][1]="1";
			InstructionNumber=0;
			for(int m=0;m<6;m++)
			{
				instructionstatus[m].Issue = 0;
				instructionstatus[m].ReadOperand = 0;
				instructionstatus[m].ExecutionComplete = 0;
				instructionstatus[m].WriteResult = 0;
			}
			char a = getch();
			goto jump;
		}
	}
	
	gotoxy(0,32);
	cout<<endl<<"Memory & Register Values"<<endl<<endl;
	cout<<"@[R1]: "<<RegisterValues[0][1]<<"    @[R2+34]: "<<RegisterValues[1][1]<<"    @[R3+45]: "<<RegisterValues[2][1]<<endl<<endl;
	cout<<"F0: "<<RegisterValues[3][1]<<"    F2: "<<RegisterValues[4][1]<<"    F4: "<<RegisterValues[5][1]<<"    F6: "<<RegisterValues[6][1]<<"    F8: "<<RegisterValues[7][1]<<"    F10: "<<RegisterValues[8][1];
}
