class MainForm : public Form
{
    SplitterFactory*  factory;  // 工厂虚基类指针

public:
    
    MainForm(SplitterFactory*  factory){    // 初始化工厂
        this->factory=factory;
    }
    
	void Button1_Click(){
        ISplitter * splitter = factory->CreateSplitter(); // 工厂多态new
        
        splitter->split();
	}
};



int main()
{
    // 二进制文件拆分对象的 生产工厂
    BinarySplitterFactory* binSplitterFac = new BinarySplitterFactory();
    
    MainForm(binSplitterFac); 

    return 0;
}

