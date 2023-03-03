//业务操作
class Stream{

public:
    virtual char Read(int number)=0;
    virtual void Seek(int position)=0;
    virtual void Write(char data)=0;
    
    virtual ~Stream(){}
};

//主体类
class FileStream: public Stream{
public:
    virtual char Read(int number){
        //读文件流
    }
    virtual void Seek(int position){
        //定位文件流
    }
    virtual void Write(char data){
        //写文件流
    }

};

class NetworkStream :public Stream{
public:
    virtual char Read(int number){
        //读网络流
    }
    virtual void Seek(int position){
        //定位网络流
    }
    virtual void Write(char data){
        //写网络流
    }
    
};

class MemoryStream :public Stream{
public:
    virtual char Read(int number){
        //读内存流
    }
    virtual void Seek(int position){
        //定位内存流
    }
    virtual void Write(char data){
        //写内存流
    }
    
};

//扩展操作
// 继承自A, 还组合了一个A接口类指针, 主要是用这个爷爷指针多态调用那仨儿子重写的虚函数
// 原本需要三个子类(加密文件/网络/内存流),现在变为一个子类，因为他们仨类的区别仅仅是read seek write, 其他的加密解密操作都一样, 所以可以多态解决
class CryptoStream: public Stream {
    
    Stream* stream;//...

public:
    CryptoStream(Stream* stm):stream(stm){}
    
    virtual char Read(int number){
        //额外的加密操作...
        stream->Read(number);       // 多态调用
    }
    virtual void Seek(int position){
        //额外的加密操作...
        stream->Seek(position);     // 多态调用
        //额外的加密操作...
    }
    virtual void Write(byte data){
        //额外的加密操作...
        stream->Write(data);        // 多态调用
        //额外的加密操作...
    }
};

class BufferedStream : public Stream{
    Stream* stream;//...
    
public:
    BufferedStream(Stream* stm):stream(stm){}
    //...
};


void Process(){

    //运行时装配
    FileStream* s1=new FileStream();            // 文件流操作对象

    CryptoStream* s2=new CryptoStream(s1);      // 装饰:加密, 在三个方法中加入了额外加密操作
    
    BufferedStream* s3=new BufferedStream(s1);  // 装饰:缓存
    
    BufferedStream* s4=new BufferedStream(s2);  // 装饰:加密+缓存
}