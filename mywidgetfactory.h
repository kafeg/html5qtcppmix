#ifndef MYWIDGETFACTORY_H
#define MYWIDGETFACTORY_H

#include <QWebPluginFactory>

class MyWidgetFactory : public QWebPluginFactory
{
    Q_OBJECT
public:
    explicit MyWidgetFactory(QObject *parent = 0);

    QObject *create(const QString &mimeType,
                    const QUrl &url, const QStringList &argumentNames,
                    const QStringList &argumentValues) const;
    QList<QWebPluginFactory::Plugin> plugins() const;

signals:

public slots:

};

#endif // MYWIDGETFACTORY_H
