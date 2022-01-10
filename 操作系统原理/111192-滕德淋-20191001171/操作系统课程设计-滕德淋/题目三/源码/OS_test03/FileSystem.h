#pragma once
/*
 *ģ���ļ�����
 */

#include<iostream>
#include<malloc.h>
#include<string.h>
using namespace std;

/*
 *�����ļ����ݽṹ
 */
typedef struct file
{
	char file_name[20];
	bool file_protect[3];
	bool open_file_protect[3]; //�����ļ���ʱ��Ч
	int  read, write; //����Ϊ��дָ��
	//int file_lenght;
	int* file_length = new int[255];
	struct file* next;
} File;

/*
 *�û����ļ���ӳ��
 */
typedef struct x_map
{
	char userName[20];
	File* file;
	struct x_map* next;
} Map;

/*
 *�������ļ�Ŀ¼
 */
typedef struct mfd
{
	Map* head, * tail;
} MFD;

/*
 *���ļ�Ŀ¼
 */
typedef struct afd
{
	File* head, * tail;
	int max_open;
	int current_open;
} AFD;

class FileSystem
{
public:
	FileSystem();
	~FileSystem();

	/*
	 *�����û��ĳ�ʼ��
	 */
	void initUser(MFD* mfd);

	/*
	*����ϵͳ�û������
	*/
	void displayUser(MFD* mfd);

	/*
	 *�����û��Ĳ��ң��ҵ��򷵻��û�ӳ��ָ��
	 */
	Map* queryUser(char userName[], MFD* mfd);

	/*
	 *�����ļ��Ĵ�������
	 *�ɹ��򷵻�true �� ���򷵻�false
	 */
	bool createFile(Map* user, char file_name[], bool file_protect[3], int file_length);

	/*
	 *�����ļ�ɾ������
	 */
	bool deleteFile(Map* user, char file_name[], AFD* afd);

	/*
	 *�����ļ��򿪲���
	 */
	bool openFile(Map* user, char file_name[], AFD* afd, bool open_file_protect[]);

	/*
	 *���ж�����
	 */
	bool readFile(AFD* afd, char file_name[]);

	/*
	 *�����ļ���д����
	 */
	bool writeFile(AFD* afd, char file_name[]);

	/*
	 *�ر��ļ�
	 */
	bool closeFile(AFD* afd, char file_name[]);

	/*
	 *�����û��ļ�����ʾ
	 */
	void displayUserFile(Map* user);

	/*
	 *��ʾ�򿪵��ļ�
	 */
	void displayOpenFile(AFD* afd, Map* user);

	/*
	* ��ʾλͼ�ļ�
	*/
	void showfile(Map* user, char file_name[]);

private:

};

