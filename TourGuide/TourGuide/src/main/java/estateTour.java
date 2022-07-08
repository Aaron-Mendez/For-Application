/*
    This is an addon to the decorator class that can be added
 */

/**
 *
 * @author aaron
 */
public class estateTour extends addOn {

    public estateTour(Tour newTour)
    {
        super(newTour);
    }
    
    @Override
    public String getDescription()
    {
        return tempTour.getDescription() + " A trolley tour of the estate grounds";
    }
    
    @Override
    public double getCost()
    {
        return tempTour.getCost() + 20;
    } 
    
    @Override
    public int getMinTimeInMinutes()
    {
        return tempTour.getMinTimeInMinutes() + 60;
    } 
}
