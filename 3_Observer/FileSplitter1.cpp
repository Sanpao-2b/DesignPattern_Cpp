// ��ֹ�����(���������, ���������ǳ����ȶ�(����ʱ��(��̬��))) , �����������Ҫ��������, ���������Ҫ�ĵĵط���(1)(2)(3)...�����������һ�����������, ȫ��Ҫ��!
class FileSplitter
{
	string m_filePath;
	int m_fileNumber;
	ProgressBar* m_progressBar;	// ���ȶ�(�仯), ��������ĸ���or��չ, �����ǻ�ı��. ���粻��ʾ��������, Ҫ���"....."��ʾ����, ����Ҫһ��Բ��תȦ

public:
	FileSplitter(const string& filePath, int fileNumber, ProgressBar* progressBar) :
		m_filePath(filePath), 
		m_fileNumber(fileNumber),
		m_progressBar(progressBar){

	}

	void split(){

		//1.��ȡ���ļ�

		//2.��������С�ļ���д��
		for (int i = 0; i < m_fileNumber; i++){
			//...
			float progressValue = m_fileNumber;
			progressValue = (i + 1) / progressValue;
			m_progressBar->setValue(progressValue);
		}

	}
};