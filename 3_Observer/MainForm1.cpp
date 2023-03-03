// 界面类
class MainForm : public Form
{
	TextBox* txtFilePath;		// 文本框 -- 输入需要拆分的文件路径
	TextBox* txtFileNumber;		// 文本框 -- 输入要拆几个
	ProgressBar* progressBar;	// 进度条 -- 输出实时进度

public:
	void Button1_Click(){

		string filePath = txtFilePath->getText();
		int number = atoi(txtFileNumber->getText().c_str());

		FileSplitter splitter(filePath, number, progressBar);	// 创建拆分工具类对象

		splitter.split();	// 拆分

	}
};

