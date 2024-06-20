class MyWizardPage : public QWizardPage {
  Q_OBJECT
public:
  MyWizardPage();
  virtual int nextId() const;
Q_SIGNALS:
  void sigLog(QString text);
};
int MyWizardPage::nextId() const {
  Q_EMIT sigLog("Something interesting happened");
}
