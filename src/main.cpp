#include "game.h"

void draw(int(*gameData)[N]);//绘图
void play(int(*gameData)[N]);//获得键值函数
int getInput();
void loadImage();

PIMAGE img_background; //开始画图
PIMAGE img_block2;
PIMAGE img_block4;
PIMAGE img_block8;
PIMAGE img_block16;
PIMAGE img_block32;
PIMAGE img_block64;
PIMAGE img_block128;
PIMAGE img_block256;
PIMAGE img_block512;
PIMAGE img_block1024;
PIMAGE img_block2048;

int loc[4]={20,142,266,390};

void draw(int(*gameData)[N])           //页面绘制
{
    int i,j;
    cleardevice();
	putimage(0, 0, img_background);
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
        	int num = gameData[i][j];
            switch(num)
            {
            case 2:
            {
                putimage_withalpha(NULL, img_block2,loc[j], loc[i]);
                break;
            }
            case 4:
            {
                putimage_withalpha(NULL, img_block4,loc[j], loc[i]);
                break;
            }
            case 8:
            {
                putimage_withalpha(NULL, img_block8,loc[j], loc[i]);
                break;
            }
            case 16:
            {
                putimage_withalpha(NULL, img_block16,loc[j], loc[i]);
                break;
            }
            case 32:
            {
                putimage_withalpha(NULL, img_block32,loc[j], loc[i]);
                break;
            }
            case 64:
            {
                putimage_withalpha(NULL, img_block64,loc[j], loc[i]);
                break;
            }
            case 128:
            {
                putimage_withalpha(NULL, img_block128,loc[j], loc[i]);
                break;
            }
            case 256:
            {
                putimage_withalpha(NULL, img_block256,loc[j], loc[i]);
                break;
            }
            case 512:
            {
                putimage_withalpha(NULL, img_block512,loc[j], loc[i]);
                break;
            }
            case 1024:
            {
                putimage_withalpha(NULL, img_block1024,loc[j], loc[i]);
                break;
            }
            case 2048:
            {
                putimage_withalpha(NULL, img_block2048,loc[j], loc[i]);
                break;
            }
            default:break;
			}
        }
    }
}

int getInput()
{
	int  ret;
	key_msg keyMsg = {0};
	keyMsg = getkey();
	if (keyMsg.msg==key_msg_down){
	switch(keyMsg.key){
		case VK_UP:
		{
			ret = UP;
			break;
		}
		case VK_DOWN:
		{
			ret = DOWN; 
			break;
		} 
		case VK_LEFT:
		{
			ret = LEFT;
			break;
		} 
		case VK_RIGHT:
		{
			ret = RIGHT;
			break;
		} 
		case 'e':
		{
			ret = EXIT;
			break;
		}	 
		default:
		{
			ret = OTHER;
			break;
		} 
	}
	}
	return ret;
}

void play(int (*gameData)[N])
{
	int key;
	key = getInput();
	switch (key) {
		case UP:{
			moveUp(gameData);
			break;
		}
		case DOWN:{
			moveDown(gameData);
			break;
		}
		case LEFT:{
			moveLeft(gameData);
			break;
		}
		case RIGHT:{
			moveRight(gameData);
			break;
		}
		case EXIT:{
			exitGame();
			break;
		}
		default:
			break;
	}
	draw(gameData);
}

void loadImage(){
	img_background = newimage();
	getimage(img_background,"img/background.png");

	img_block2 = newimage();
	getimage(img_block2,"img/block_2.png");
	img_block4 = newimage();
	getimage(img_block4,"img/block_4.png");
	img_block8 = newimage();
	getimage(img_block8,"img/block_8.png");
	img_block16 = newimage();
	getimage(img_block16,"img/block_16.png");
	img_block32 = newimage();
	getimage(img_block32,"img/block_32.png");
	img_block64 = newimage();
	getimage(img_block64,"img/block_64.png");
	img_block128 = newimage();
	getimage(img_block128,"img/block_128.png");
	img_block256 = newimage();
	getimage(img_block256,"img/block_256.png");
	img_block512 = newimage();
	getimage(img_block512,"img/block_512.png");
	img_block1024 = newimage();
	getimage(img_block1024,"img/block_1024.png");
	img_block2048 = newimage();
	getimage(img_block2048,"img/block_2048.png");

}

int  main()
{
	int gameData[N][N];
	initGame(gameData);
    initgraph(BACK_SIZE, BACK_SIZE);//初始化
    setcaption("2048");
    loadImage();
	
	flushkey();
	
	draw(gameData);
	
    for(;is_run();delay_fps(60)){
        play(gameData);
    }

	return 0;
}
	
