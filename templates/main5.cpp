template <typename TargetType> class Configurator {
    TargetType * mTarget;
/*
    const Configuration & mConfiguration;
    Logging::Module & mLog;
*/
public:
/*
    Configurator(TargetType * aTarget, const Configuration & aConfiguration);
    Configurator(TargetType * aTarget, const Configuration & aConfiguration, Logging::Module & aLog);
    ~Configurator();
*/
    template <typename ParamType>
    void readParam(void (TargetType::*aSetter)(ParamType), const std::string & aParamName);

    template <typename ParamType>
    void readParam(void (TargetType::*aSetter)(const ParamType &), const std::string & aParamName);

    template <typename ParamType>
    void readParam(void (TargetType::*aSetter)(System::SmartPtr<ParamType>), const std::string & aParamName);

private:
    template <typename ParamType, typename SetterType>
    void readParam(SetterType aSetter, const std::string & aParamName);
};

/*
template <typename TargetType>
Configurator<TargetType>::Configurator(TargetType * aTarget, const Configuration & aConfiguration)
    : Configurator<TargetType>::Configurator(aTarget, aConfiguration, Logging::Logging::getInstance().getSubModule("Configurator"))
{
}

template <typename TargetType>
Configurator<TargetType>::Configurator(TargetType * aTarget, const Configuration & aConfiguration, Logging::Module & aLog)
    : mTarget(aTarget), mConfiguration(aConfiguration), mLog(aLog)
{
}

template <typename TargetType>
Configurator<TargetType>::~Configurator()
{
}
*/
template <typename TargetType>
template <typename ParamType>
void Configurator<TargetType>::readParam(void (TargetType::*aSetter)(ParamType), const std::string & aParamName)
{
    readParam<ParamType, void (TargetType::*)(ParamType)>(aSetter, aParamName);
}

template <typename TargetType>
template <typename ParamType>
void Configurator<TargetType>::readParam(void (TargetType::*aSetter)(const ParamType &), const std::string & aParamName)
{
    readParam<ParamType, void (TargetType::*)(const ParamType &)>(aSetter, aParamName);
}

template <typename TargetType>
template <typename ParamType>
void Configurator<TargetType>::readParam(void (TargetType::*aSetter)(System::SmartPtr<ParamType>), const std::string & aParamName)
{
    ConfiguratorHelper<TargetType, ParamType>::readParam(mTarget, mConfiguration, mLog, aSetter, aParamName);
}

template <typename TargetType>
template <typename ParamType, typename SetterType>
void Configurator<TargetType>::readParam(SetterType aSetter, const std::string & aParamName)
{
    if (mConfiguration.hasSubValue(aParamName)) {
        bool error = false;
        ParamType value = mConfiguration.getSubValue(aParamName).getValueAs<ParamType>(error);

        if (!error) {
            (mTarget->*aSetter)(value);
        } else {
            mLog.warning("Could not read configuration parameter: %s", aParamName.c_str());
        }
    } else {
        mLog.warning("Parameter not declared: %s", aParamName.c_str());
    }
}
/*
template <typename TargetType, typename ParamType>
class ConfiguratorHelper
{
public:
    static void readParam(TargetType * aTarget, const Configuration & aConfiguration, Logging::Module & aLog, void (TargetType::*aSetter)(System::SmartPtr<ParamType>), const std::string & aParamName);
};
*/
int main(){}