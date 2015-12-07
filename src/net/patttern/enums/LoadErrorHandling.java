package net.patttern.enums;

import com.sun.jna.Structure;

/**
 * Created by ebabenko on 07.12.15.
 */
public class LoadErrorHandling extends Structure {
  public int abort;
  public int skip;
  public int ignore;
}
