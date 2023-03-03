class MainForm : public Form
{
	TextBox* txtFilePath;
	TextBox* txtFileNumber;
	ProgressBar* progressBar;

public:
	void Button1_Click(){

		ISplitter * splitter=		// 很好, 这个ISplitter很稳定, 虚基类指针, 动态绑定
            new BinarySplitter();	// 这里不好了, new编译时绑定, 依赖具体类, 为了解决这个问题, 借助工厂模式
        
        splitter->split();

	}
};