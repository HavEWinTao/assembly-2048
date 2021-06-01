#ifndef _GAME_H_
#define _GAME_H_

#include<graphics.h>
#include<stdlib.h>
#include<time.h>

#define N 4 //��Ϸ��ά��

enum KEY
{
	UP,     //��
	DOWN,   //��
	LEFT,   //��
	RIGHT,  //��
	EXIT,   //�˳�
	OTHER   //������
};

/*
 * ������:initGame
 * ����:����Ϸ�������ݽ��г�ʼ�������������������
 * ����:��Ҫ��ʼ������Ϸ����
 * ����ֵ:��
*/
void initGame(int data[N][N]);

/*
 * ������:getRand
 * ����:����Ϸ�����в���һ���������2�ĸ���Ϊ80%��4�ĸ���Ϊ20%
 * ����:��Ҫ�������������Ϸ����
 * ����ֵ:��
*/
void getRand(int data[N][N]);

/*
 * ������:checkGameOver
 * ����:�����Ϸ�Ƿ����
 * ����:��Ҫ������Ϸ����
 * ����ֵ:��Ϸ��������1��û�н�������0
*/
int checkGameOver(int data[N][N]);

/*
 * ������:exitGame
 * ����:�˳���Ϸ
 * ����:��
 * ����ֵ:��
 */
void exitGame(void);

/*
 * ������:maxScore
 * ����:��ȡ��Ϸ�����е������
 * ����:��Ҫ���ҵ���Ϸ����
 * ����ֵ:��Ϸ�����е����ֵ
*/
int maxScore(int data[N][N]);

/*
 * ������:moveUp
 * ����:����Ϸ��������
 * ����:��Ҫ���Ƶ���Ϸ����
 * ����ֵ:��
 */
void moveUp(int data[N][N]);

/*
* ������:moveDown
* ����:����Ϸ��������
* ����:��Ҫ���Ƶ���Ϸ����
* ����ֵ:��
*/
void moveDown(int data[N][N]);

/*
* ������:moveLeft
* ����:����Ϸ��������
* ����:��Ҫ���Ƶ���Ϸ����
* ����ֵ:��
*/
void moveLeft(int data[N][N]);

/*
* ������:moveRight
* ����:����Ϸ��������
* ����:��Ҫ���Ƶ���Ϸ����
* ����ֵ:��
*/
void moveRight(int data[N][N]);

/*
 * ������:getInput
 * ����:��ȡ�û�������
 * ����:��
 * ����ֵ:�����û�����İ���
*/

int checkGameWin(int maxScore);

#endif