// In this we will work on the modules job/internship program/registration by HR, Apply for jobs(by candidates), Update/delete the job, Update candidates details, candidate registration
# include <stdio.h>
# include <string.h>
# include <conio.h>
# include <stdlib.h>
int candidate_registration();
int Job_registration_hr();
int delete_job();
int new_user();
int apply_jobs();
int update_candidates_details();

struct user{
	char id[30];
	char password[30];
};

int new_user(){
	int a;
	struct user user1;
	FILE *fp;
	fp=fopen("user_password.txt","wb");
	printf("enter user name : ");
	scanf("%s",&user1.id);
	printf("enter password : ");
	scanf("%s",&user1.password);
	fprintf(fp,"%s\n%s",user1.id,user1.password);
	fclose(fp);
	printf("\nlogin successfull\n");
	printf("Enter 1 for candidate registration : \nEnter 2 for applying for a job : \nEnter 3 for profile updation : ");
	scanf("%d",&a);
	switch(a){
		case 1:
			candidate_registration();
			break;
		case 2:
			apply_jobs();
			break;
	}
	return 0;
}
int main(){
	int a,value1,value2,b;
	char developer_id[50],developer_password[50];
	printf("\n If you are a developer enter 1 \n Enter 2 if you are a new user : \n");
	scanf("%d",&a);
	
// code to ask the user weather he is a HR or user

	switch(a){
		case 1:
			printf("\nEnter your user name : \n");
			scanf("%s",&developer_id);
			printf("\nEnter your  password : \n");
			scanf("%s",&developer_password);
			value1=strcmp(developer_id,"developer");
			value2=strcmp(developer_password,"developer");
	
		if(value1==0 & value2==0){
			printf("\nlogin succesfull\n\n");
			printf("\n Enter 1 to upload available jobs \n Enter 2 to update or delete the jobs : ");
			scanf("%d",&b);
		}
		else{
			printf("\n incorrect id or password \n");
		}
		
		switch(b){
		case 1:
			Job_registration_hr();
			break;
		
		case 2:
			delete_job();
			break;
			
		default:
			printf("Invalid case");
			break;
		}
			break;
	
			
		case 2:
			new_user();
		break;

	
		return 0;
	}
}


struct hr_job_registration{
	char job_name[50];
	char job_description[100];
	char eligibility[100];
};

int Job_registration_hr(){
	int a;
	FILE *fp;
	fp=fopen("job.txt","ab+");
	struct hr_job_registration job;

		printf("Enter job title : \n");
		scanf("%s",&job.job_name);
		fflush(stdin);
		printf("Enter job description : \n");
		scanf("%s",&job.job_description); 
		fflush(stdin); 		
		printf("Enter job elegibility : \n");
		scanf("%s",&job.eligibility); 
		fflush(stdin); 
		fwrite(&job,sizeof(job),1,fp);
		printf("%s\n%s\n%s\n\n",job.job_name,job.job_description,job.eligibility);
	fclose(fp);	
	printf("enter 1 to register another job \n Enter 2 to delete job \n 3 to exit : ");
	scanf("%d",&a);
	switch(a){
		case 1:
		Job_registration_hr();
		break;
		
		case 2:
			delete_job();
			break;
			
		case 3:
		return 0;
		break;	
	}
	return 0;
	
}




int delete_job(){
	FILE *fp,*ft;
	char name[40];
	fp=fopen("job.txt","ab+");
	ft=fopen("job1.txt","ab+");
	struct hr_job_registration job;
	printf("These are the avalable jobs in the file : \n");
	while(fread(&job,sizeof(job),1,fp)==1){
		printf("\n%s \t %s \t% s\n",job.job_name,job.job_description,job.eligibility);
	}
	printf("\nEnter the name of the record that is to be deleted : ");
	scanf("%s",&name);
	while(fread(&job,sizeof(job),1,fp)==1){
		if(strcmp(name,job.job_name)!=0){
			fwrite(&job,sizeof(job),1,ft);
		}

	}
		fclose(fp);
		fclose(ft);
		remove("job.txt");
		rename("job1.txt","job.txt");
		while(fread(&job,sizeof(job),1,fp)==1){
			printf("%s \t %s \t% s",job.job_name,job.job_description,job.eligibility);
	}
	printf("Record deleted successfull.");
	return 0;

}


// 2nd module::candidate registration.
struct name{
 	char firstname[20];
 	char lastname[40];
 };
 struct candidate{
 	struct name full;
 	int age;
 	char qualification[50];
 	char adress[100];
 	double phone;
 	char mail[50];
 };
// taking inputs from the user to register
int candidate_registration(){
	FILE *info;
	info=fopen("user.txt","w+");
	struct candidate details;
	printf("FIRSTNAME: ");
	scanf("%s",details.full.firstname);
	printf("LASTNAME: ");
	scanf("%s",details.full.lastname);
	printf("AGE: ");
	scanf("%d",&details.age);
	printf("QUALIFICATION : ");
	scanf("%s",details.qualification);
	printf("ADDRESS: ");
	scanf("%s",details.adress);
	printf("PHONE NUMBER: ");
	scanf("%lf",&details.phone);
	printf("EMAIL: ");
	scanf("%s",details.mail);
// printing the info given by the candidate
	printf("\n\nDETAILS OF THE CANDIDATE ARE : \n");
	printf("FULL NAME: %s %s\n",details.full.firstname,details.full.lastname);
	printf("AGE: %d\n",details.age);
	printf("QUALIFICATION : %s\n",details.qualification);
	printf("ADDRESS : %s\n",details.adress);
	printf("PHONE NUMBER: %lf\n",details.phone);
	printf("EMAIL : %s\n",details.mail);
	fwrite(&details,sizeof(details),1,info);
	fclose(info);
	fclose;
	printf("\nNow you will be redirected to apply jobs. \n");
	apply_jobs();
	return 0;
}


int apply_jobs(){
	char jobs[50],condition[20];
	printf("\n\nHere we go,We are having some vacant jobs for :\n1)developer\n2)manager\n3)programmer\n4)analyst\n");
	printf("\nTell us which job are you looking for : ");
	scanf("%s",jobs);
	int value1,value2,value3,value4,value5;
	value1=strcmp(jobs,"developer");
	if (value1==0){
		printf("\n\nWelcome,You are applying for the Developer domain\n");
		printf("I have Read all Your detailes.\n");
		printf("If you wants to join for this job you should agree for the terms and condition.\n1)you should sign on the bond for 2  years agreement\n2)And There are limited leaves only .\nIf you are agreed for this terms then enter :yes. if no enter :no\n");
		scanf("%s",condition);
		value2=strcmp(condition,"yes");
		if (value2==0) {
			printf("Yeah you are eligible for this job.");
	}
		else{
			printf("your application is under process.");
	}
}
	value3=strcmp(jobs,"manager");
	if (value3==0){
		printf("\n\nWelcome,You are applying for the Manager domain\n");
		printf("I have Read all Your detailes.\n");
		printf("If you wants to join for this job you should agree for the terms and condition.\n1)you should sign on the bond for 2  years agreement\n2)And There are limited leaves only .\nIf you are agreed for this terms then enter :yes. if no enter :no\n");
		scanf("%s",condition);
		value2=strcmp(condition,"yes");
		if (value2==0) {
			printf("Yeah you are eligible for this job.");
	}
		else{
			printf("your application is under process.");
		}
	}
	value4=strcmp(jobs,"programmer");
	if (value4==0){
		printf("\n\nWelcome,You are applying for the programmer domain\n");
		printf("I have Read all Your detailes.\n");
		printf("If you wants to join for this job you should agree for the terms and condition.\n1)you should sign on the bond for 2  years agreement\n2)And There are limited leaves only .\nIf you are agreed for this terms then enter :yes. if no enter :no\n");
		scanf("%s",condition);
		value2=strcmp(condition,"yes");
		if (value2==0) {
			printf("Yeah you are eligible for this job.");
	}
		else{
			printf("your application is under process.");
		}
	}
	value5=strcmp(jobs,"analyst");
	if (value5==0){
		printf("\n\nWelcome,You are applying for the system analyst domain\n");
		printf("I have Read all Your detailes.\n");
		printf("If you wants to join for this job you should agree for the terms and condition.\n1)you should sign on the bond for 2  years agreement\n2)And There are limited leaves only .\nIf you are agreed for this terms then enter :yes. if no enter :no\n");
		scanf("%s",condition);
		value2=strcmp(condition,"yes");
		if (value2==0) {
			printf("Yeah you are eligible for this job.");
	}
		else{
			printf("your application is under process.");
		}
	}
	return 0;
}