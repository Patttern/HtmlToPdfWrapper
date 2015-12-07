package net.patttern.classes;

import com.sun.jna.Structure;
import net.patttern.enums.ProxyType;

/**
 * Created by ebabenko on 07.12.15.
 */
public class Proxy extends Structure {
/*
  Proxy();
  //! Type of proxy to use
  QNetworkProxy::ProxyType type;
  //! The port of the proxy to use
  int port;
  //! The host name of the proxy to use or NULL
  QString host;
  //! Username for the said proxy or NULL
  QString user;
  //! Password for the said proxy or NULL
  QString password;
*/
  public ProxyType type;
  public Integer port;
  public String host;
  public String user;
  public String password;

  public Proxy() {
  }
}
