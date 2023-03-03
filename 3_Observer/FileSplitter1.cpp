// 拆分工具类(这个案例中, 这个工具类非常不稳定(编译时绑定(静态绑定))) , 想想如果我们要更改需求, 这个工具类要改的地方有(1)(2)(3)...我这个工具类一共就三块代码, 全都要改!
class FileSplitter
{
	string m_filePath;
	int m_fileNumber;
	ProgressBar* m_progressBar;	// 不稳定(变化), 随着需求的更改or扩展, 这里是会改变的. 比如不显示进度条了, 要输出"....."显示进度, 或者要一个圆形转圈

public:
	FileSplitter(const string& filePath, int fileNumber, ProgressBar* progressBar) :
		m_filePath(filePath), 
		m_fileNumber(fileNumber),
		m_progressBar(progressBar){

	}

	void split(){

		//1.读取大文件

		//2.分批次向小文件中写入
		for (int i = 0; i < m_fileNumber; i++){
			//...
			float progressValue = m_fileNumber;
			progressValue = (i + 1) / progressValue;
			m_progressBar->setValue(progressValue);
		}

	}
};