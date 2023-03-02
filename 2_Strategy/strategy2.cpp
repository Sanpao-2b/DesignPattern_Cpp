

// 抽象基类(接口类)
class TaxStrategy{
public:
    virtual double Calculate(const Context& context)=0;
    virtual ~TaxStrategy(){}
};


class CNTax : public TaxStrategy{
public:
    virtual double Calculate(const Context& context){
        //***********
    }
};

class USTax : public TaxStrategy{
public:
    virtual double Calculate(const Context& context){
        //***********
    }
};

class DETax : public TaxStrategy{
public:
    virtual double Calculate(const Context& context){
        //***********
    }
};



//扩展 随意扩展
//*********************************
class FRTax : public TaxStrategy{
public:
	virtual double Calculate(const Context& context){
		//.........
	}
};

// 现在这个类就非常稳定
class SalesOrder{
private:
    TaxStrategy* strategy;      // 接入了一个接口(组合方式),这个接口是一个抽象基类指针, 运行时指向一个具体的税种(运行时依赖)
    // strategyFactory* factory;     // 不需要
public:
    // 因为我们组合了一个 TaxStrategy虚函数指针, 我们要对它赋值, 如果是直接 strategy = new "具体国家的税种类", 则会引入一个编译时依赖, new后面的东西是变化的!
    // 工厂模式---- 解决对象创建 所带来的编译时依赖问题!
    //        ---- 有了工厂模式后, 这个类才真正达到一个巨稳定状态, 不管你要计算什么国家的税, 新增多少国家, 我这个SalesOrder类都不用做更改
    //        ---- 跟后面的工厂案例不同的是, 这里不需要拥有一个工厂基类指针成员变量, 直接构造函数里就用传进来的具体类来实例化strategy了
    SalesOrder(StrategyFactory* strategyFactory){
        //strategy = strategyFactory;
        this->strategy = strategyFactory->NewStrategy();
    }
    ~SalesOrder(){
        delete this->strategy;
    }

    public double CalculateTax(){           // 这个calculate函数, 不管新增多少种国家, 都不用改变 包括这个类SalesOrder 都不用改变 非常稳定
        //...
        Context context();
        
        double val = strategy->Calculate(context); //多态调用
        //...
    }
    
};


int main()
{

    // 我要计算法国的税, 则传入法国
    SalesOrder so(FRTax);
    so.
    return 0;
}
