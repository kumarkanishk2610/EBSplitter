#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>

int units,category=0;
float amount=0;
float tier1rate=0;
float tier2rate=0;
float tier3rate=0;
float tier4rate=0;
float tier1amt=0;
float tier2amt=0;
float tier3amt=0;
float tier4amt=0;
float tier1units=0;
float tier2units=0;
float tier3units=0;
float tier4units=0;
float fmc=0;
int closescan=0;

int AC1units,AC2units,AC3units,ACtotalunits,commontotalunits;

void test()
        {
            printf("Testing External Variable writing: %d",ACtotalunits);
        }


void ACCALC(int category,float total)
            {
                int AC1units, AC2units, AC3units, ACtotalunits, nonACtotalunits;
                printf("\n\nEnter AC1 Units: ");
                scanf("%d",&AC1units);
                printf("\nEnter AC2 Units: ");
                scanf("%d",&AC2units);
                printf("\nEnter AC3 Units: ");
                scanf("%d",&AC3units);
                ACtotalunits=AC1units+AC2units+AC3units;
                nonACtotalunits=units-ACtotalunits;
                printf("\n============================================");
                printf("\nTotal AC Units are :              %d Units",ACtotalunits);
                printf("\nTotal Non-AC(Common) Units are :  %d Units",nonACtotalunits);
                printf("\n============================================");
                printf("\nCategory Test: %d", category);
               
                float ACbill;                
                switch(category)
                    {
                        case 4:
                                {
                                    if(nonACtotalunits>500)
                                        {
                                            ACbill=((ACtotalunits)*6.6);
                                        }
                                    else if(nonACtotalunits>200&&nonACtotalunits<=500)
                                        {
                                            ACbill=((units-500)*6.6)+((500-nonACtotalunits)*4.6);
                                        }
                                    else if(nonACtotalunits>100&&nonACtotalunits<=200)
                                        {
                                            ACbill=((units-500)*6.6)+((300)*4.6)+((200-nonACtotalunits)*3.5);
                                        }
                                    else if(nonACtotalunits>0&&nonACtotalunits<=100)
                                        {
                                            ACbill=((units-500)*6.6)+((300)*4.6)+((100)*3.5)+((100-nonACtotalunits)*0);
                                        }
                                    else
                                        {
                                            printf("\nERROR IN CAT4!");
                                        }
                                };
                                break;
                        case 3:
                                {
                                    if(nonACtotalunits>200&&nonACtotalunits<=500)
                                        {
                                            ACbill=((ACtotalunits)*3);
                                            printf("1");
                                        }
                                    else if(nonACtotalunits>100&&nonACtotalunits<=200)
                                        {
                                            ACbill=((units-200)*3)+((200-nonACtotalunits)*2);
                                            printf("2");
                                        }
                                    else if(nonACtotalunits>0&&nonACtotalunits<=100)
                                        {
                                            ACbill=((units-200)*3)+((100)*2)+((100-nonACtotalunits)*0);
                                            printf("3");
                                        }
                                    else   
                                        {
                                            printf("\nERROR IN CAT3!");
                                        }
                                };
                                break;
                        case 2:
                                {
                                    if(nonACtotalunits>100&&nonACtotalunits<=200)
                                        {
                                            ACbill=((ACtotalunits)*1.5);
                                        }
                                    else if(nonACtotalunits>0&&nonACtotalunits<=100)
                                        {
                                            ACbill=((units-100)*1.5)+((100-nonACtotalunits)*0);
                                        }
                                    else   
                                        {
                                            printf("\nERROR IN CAT2!");
                                        }
                                };
                                break;
                        case 1:
                                {
                                    if(nonACtotalunits>0&&nonACtotalunits<=100)
                                        {
                                            ACbill=(100-nonACtotalunits)*0;
                                        }
                                    else   
                                        {
                                            printf("\nERROR IN CAT1!");
                                        }
                                };
                                break;
                        default:
                                {
                                    printf("\nDEFAULTERROR!");
                                };
                        
                    }

                
                printf("\n============================================");
                printf("\nPlease enter the number of tenants for common share: ");
                int tenants;
                scanf("%d",&tenants);
                printf("\nTotal AC Electricity Cost is Rs %.2f",ACbill);
                printf("\nAC Bill Splitting per room:");
                float commonratio=ACbill/ACtotalunits;
                float AC1bill=AC1units*commonratio;
                float AC2bill=AC2units*commonratio;
                float AC3bill=AC3units*commonratio;
                printf("\nCost for AC1 = Rs %.2f",AC1bill);
                printf("\nCost for AC2 = Rs %.2f",AC2bill);
                printf("\nCost for AC3 = Rs %.2f",AC3bill);
                float equalpartcommon=(total-ACbill)/tenants;
                printf("\nCommon Bill = Rs %.2f Per Head for %d tenants",equalpartcommon,tenants);
                printf("\n============================================");
                
                getchar();

            }

void amtcalculator( float tier1rate,    float tier2rate,    float tier3rate,    float tier4rate,
                    float tier1units,   float tier2units,   float tier3units,   float tier4units,
                    float fmc,          int category)
            {
                tier1amt=tier1rate*tier1units;
                tier2amt=tier2rate*tier2units;
                tier3amt=tier3rate*tier3units;
                tier4amt=tier4rate*tier4units; 
                printf("\nUnits Consumed = %d",units);
                printf("\n==================================");
                printf("\nBifurcation:");
                printf("\n%.2f Units * Rs %.2f = Rs %.2f", tier1units,tier1rate,tier1amt);
                printf("\n%.2f Units * Rs %.2f = Rs %.2f", tier2units,tier2rate,tier2amt);
                printf("\n%.2f Units * Rs %.2f = Rs %.2f", tier3units,tier3rate,tier3amt);
                printf("\n%.2f Units * Rs %.2f = Rs %.2f", tier4units,tier4rate,tier4amt);
                printf("\nFixed Monthly Charges = %.2f",fmc);
                float total=tier1amt+tier2amt+tier3amt+tier4amt+fmc;
                printf("\nCalculated Amount = %.2f", total);
                ACCALC(category,total);
            }

void type1()
            {   category=1;
                amtcalculator(0,0,0,0,units,0,0,0,0,1);
                getchar();
                printf("Enter any Input to Exit: ");
                scanf("%d",&closescan);
                (closescan==0)?(exit(0)):(exit(0));
            }


void type2()
            {   category=2;
                tier2units=units-100;
                amtcalculator(0,1.50,0,0,100,tier2units,0,0,20,2);
                getchar();
                printf("Enter any Input to Exit: ");
                scanf("%d",&closescan);
                (closescan==0)?(exit(0)):(exit(0));
            }

void type3()
            {   category=3;
                tier3units=units-200;
                amtcalculator(0,2,3,0,100,100,tier3units,0,30,3);
                getchar();
                printf("Enter any Input to Exit: ");
                scanf("%d",&closescan);
                (closescan==0)?(exit(0)):(exit(0));
            }

void type4()
            {   category=4;
                tier4units=units-500;
                amtcalculator(0,3.5,4.6,6.6,100,100,300,tier4units,50,4);
                getchar();
                printf("Enter any Input to Exit: ");
                scanf("%d",&closescan);
                (closescan==0)?(exit(0)):(exit(0));
            }

void switcher()
            {
                switch(units)
                    {   
                        case 0 ... 100:
                            type1();
                        case 101 ... 200:
                            type2();
                        case 201 ... 500:
                            type3();
                        case 501 ... 99999999:
                            type4();
                        default:
                            printf("\nInvalid Input!");  
                    }
            }

int main()
    {
        printf("\n\nTANGEDCO Electricity Bill Splitter");
        printf("\n==================================");
        printf("\nThe bill will be split into 3 parts, according to the number of AC units consumed.");
        printf("\n==================================");
        printf("\nPlease enter the number of units consumed: ");
        scanf("%d",&units);
        printf("\n==================================");
        switcher();
        return 0;
    }