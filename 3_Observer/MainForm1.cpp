// ������
class MainForm : public Form
{
	TextBox* txtFilePath;		// �ı��� -- ������Ҫ��ֵ��ļ�·��
	TextBox* txtFileNumber;		// �ı��� -- ����Ҫ�𼸸�
	ProgressBar* progressBar;	// ������ -- ���ʵʱ����

public:
	void Button1_Click(){

		string filePath = txtFilePath->getText();
		int number = atoi(txtFileNumber->getText().c_str());

		FileSplitter splitter(filePath, number, progressBar);	// ������ֹ��������

		splitter.split();	// ���

	}
};

