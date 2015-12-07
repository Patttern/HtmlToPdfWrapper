package net.patttern.classes;

import com.sun.jna.Structure;

/**
 * Created by ebabenko on 07.12.15.
 */
public class Margin extends Structure {
/*
  Margin();
  //!Margin applied to the top of the page
  UnitReal top;
  //!Margin applied to the right of the page
  UnitReal right;
  //!Margin applied to the bottom of the page
  UnitReal bottom;
  //!Margin applied to the leftp of the page
  UnitReal left;
*/
  public UnitReal top;
  public UnitReal right;
  public UnitReal bottom;
  public UnitReal left;

  public Margin() {
  }
}
