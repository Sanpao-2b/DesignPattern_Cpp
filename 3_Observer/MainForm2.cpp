// ���ĺ��
class MainForm : public Form, public IProgress
{
	TextBox* txtFilePath;
	TextBox* txtFileNumber;
	ProgressBar* progressBar;

public:
	void Button1_Click(){

		string filePath = txtFilePath->getText();
		int number = atoi(txtFileNumber->getText().c_str());

		ConsoleNotifier cn;

		FileSplitter splitter(filePath, number);

		splitter.addIProgress(this); //����֪ͨ �Լ�Ҳ�Ǹ��۲���, ��ʵҲ���Բ���, ֻ��Ҫ��progressBar��ɸ�cnһ�� �������, ��д���� ����MainForm�����ɾ�һЩ 
		splitter.addIProgress(&cn); //����֪ͨ

		splitter.split();

		splitter.removeIProgress(this);

	}

	virtual void DoProgress(float value){
		progressBar->setValue(value);
	}
};

//////////////////////////////////// ��չ
class ConsoleNotifier : public IProgress {
public:
	virtual void DoProgress(float value){
		cout << ".";
	}
};

class ConsoleNotifier : public IProgress {
public:
	virtual void DoProgress(float value){
		cout << ".";
	}
};
