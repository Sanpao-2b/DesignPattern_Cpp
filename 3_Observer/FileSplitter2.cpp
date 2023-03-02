// �����(�ӿ���)
class IProgress{
public:
	virtual void DoProgress(float value)=0;	 // �۲���ģʽ(�¼�)����Ϸ��Ҳ�õü����, ������֪ͨ���۲���, ���Դ���һЩ����, �۲����ǿ��Ը���������������Լ�����Ϊ
	virtual ~IProgress(){}
};


class FileSplitter
{
	string m_filePath;
	int m_fileNumber;

	List<IProgress*>  m_iprogressList; // ����֪ͨ���ƣ�֧�ֶ���۲���
	
public:
	FileSplitter(const string& filePath, int fileNumber) 
		: m_filePath(filePath), m_fileNumber(fileNumber){}

	void split(){
		//1.��ȡ���ļ�
		//2.��������С�ļ���д��
		for (int i = 0; i < m_fileNumber; i++){
			//���.....

			// ���ȼ���
			float progressValue = m_fileNumber;
			progressValue = (i + 1) / progressValue;
			onProgress(progressValue);	// ����֪ͨ
		}

	}

	// ��۲����б�����ӹ۲���
	void addIProgress(IProgress* iprogress){
		m_iprogressList.push_back(iprogress);
	}

	void removeIProgress(IProgress* iprogress){
		m_iprogressList.remove(iprogress);
	}


private:
	
	virtual void onProgress(float value){
		for (auto obj : m_iprogressList){
			obj.DoProgress();
		}
	}
};