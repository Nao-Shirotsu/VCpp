// FirstGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "first.h"
#include <iostream>


int main(){
    
	int x, y;
	int count = 1; //マスをとった回数をカウント
	int judge = 0; //勝利条件判定用変数

	first frt;

	std::cout << "三目ならべ！！\n" << std::endl;

	while(count <= 9){

		frt.Indicate();

		judge = frt.Judge();

		if (judge) {
		
			if (judge == CIRCLE) {
			
				std::cout << "oの勝ち！" << std::endl;
				return 0;
			
			}
			
			if(judge == CROSS){
			
				std::cout << "xの勝ち！" << std::endl;
				return 0;
			
			}
		
		}

		std::cout << "占領したいマスの座標を入力してください：";

		std::cin >> x;
		std::cin >> y;

		frt.Set(x , y);

		if (x < 1 || 3 < x || y < 1 || 3 < y) {
		
			std::cout << "座標の値が不正です。" << std::endl;

			continue;
		
		}else if(frt.GetStatus() == CIRCLE || frt.GetStatus() == CROSS) {

			std::cout << "そのマスはすでに埋まっています。" << std::endl;

			continue;

		}else{

			if(count % 2) {

				frt.SetCircle();

			}else {

				frt.SetCross();

			}

			count++;

		}

	}

	frt.Indicate();

	std::cout << "引き分け！" << std::endl;

	return 0;
}
