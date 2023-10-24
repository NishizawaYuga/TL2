#include <cstdio>
#include <cstdlib>
#include <DirectXTex.h>
#include "TextureConverter.h"

//コマンドライン引数
enum Argument {
	kApplicationPath,	//アプリケーションのパス
	kFilePath,			//渡されたファイルのパス

	NumArgument
};

int main(int argc,char* argv[]) {

	//assert(argc >= NumArgument);

	//COMライブラリの初期化
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	//テクスチャコンバータ
	TextureConverter converter;

	//テクスチャ変換
	converter.ConvertTextureWICToDDS(argv[kFilePath]);

	//COMライブラリの終了
	CoUninitialize();

	//argcの数だけ繰り返す
	//for (int i = 0; i < argc; i++) {
	//	//文字列のargvのi番を表示
	//	printf(argv[i]);
	//	//改行
	//	printf("\n");
	//}

	//printf("Hello,World!\n");

	system("pause");
	return 0;
}