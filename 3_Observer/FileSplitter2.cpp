// 虚基类(接口类)
class IProgress{
public:
	virtual void DoProgress(float value)=0;	 // 观察者模式(事件)在游戏中也用得极其多, 他发出通知给观察者, 可以传递一些参数, 观察者们可以根据这个参数做出自己的行为
	virtual ~IProgress(){}
};


class FileSplitter
{
	string m_filePath;
	int m_fileNumber;

	List<IProgress*>  m_iprogressList; // 抽象通知机制，支持多个观察者
	
public:
	FileSplitter(const string& filePath, int fileNumber) 
		: m_filePath(filePath), m_fileNumber(fileNumber){}

	void split(){
		//1.读取大文件
		//2.分批次向小文件中写入
		for (int i = 0; i < m_fileNumber; i++){
			//拆分.....

			// 进度计算
			float progressValue = m_fileNumber;
			progressValue = (i + 1) / progressValue;
			onProgress(progressValue);	// 发送通知
		}

	}

	// 向观察者列表中添加观察者
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