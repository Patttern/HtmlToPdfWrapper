package net.patttern.enums;

import com.sun.jna.Structure;

/**
 * Created by ebabenko on 07.12.15.
 */
public class ProxyType extends Structure {
  public int DefaultProxy;
  public int Socks5Proxy;
  public int NoProxy;
  public int HttpProxy;
  public int HttpCachingProxy;
  public int FtpCachingProxy;
}
